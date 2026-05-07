/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:10:08 by abelov            #+#    #+#             */
/*   Updated: 2026/05/07 14:10:09 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define POOL_CAP 8
#define NIL -1
#define PAYLOAD_CAP 32

typedef struct Packet
{
	int id;
	size_t len;
	char payload[PAYLOAD_CAP];
}	Packet;

typedef struct Slot {
	struct Packet packet;
	int next;
	int used;
}	Slot;

typedef struct PacketPool {
	struct Slot slots[POOL_CAP];
	int free_head;
	int active_head;
}	PacketPool;

void pool_init(PacketPool *pool)
{
	int i = -1;
	while (++i < POOL_CAP) {
		pool->slots[i].next = i + 1;
		pool->slots[i].used = 0;
	}

	pool->slots[POOL_CAP - 1].next = NIL;
	pool->free_head = 0;
	pool->active_head = NIL;
}

int pool_alloc(struct PacketPool *pool)
{
	if (pool->free_head == NIL)
		return NIL;

	int idx = pool->free_head;
	pool->free_head = pool->slots[idx].next;

	pool->slots[idx].used = 1;

	pool->slots[idx].next = pool->active_head;
	pool->active_head = idx;

	return idx;
}

int pool_free(struct PacketPool *pool, int idx)
{
	if (idx < 0 || idx >= POOL_CAP || pool->slots[idx].used == 0)
		return -1;

	int cur = pool->active_head;
	int prev = NIL;

	while (cur != NIL) {
		if (cur == idx)
			break;

		prev = cur;
		cur = pool->slots[cur].next;
	}

	if (cur == NIL)
		return -1;

	if (prev == NIL)
		pool->active_head = pool->slots[cur].next;
	else
		pool->slots[prev].next = pool->slots[cur].next;

	pool->slots[idx].used = 0;
	pool->slots[idx].next = pool->free_head;
	pool->free_head = idx;

	return 0;
}

void packet_set(struct PacketPool *pool, int idx, int id, const char *text)
{
	struct Packet *pkt;

	pkt = &pool->slots[idx].packet;

	pkt->id = id;
	snprintf(pkt->payload, sizeof(pkt->payload), "%s", text);
	pkt->len = strlen(pkt->payload);
}

void dump_active(struct PacketPool *pool)
{
	int cur = pool->active_head;

	printf("active packets:\n");

	while (cur != NIL) {
		struct Packet *pkt = &pool->slots[cur].packet;

		printf("  slot=%d id=%d len=%zu payload=\"%s\" next=%d\n",
			   cur,
			   pkt->id,
			   pkt->len,
			   pkt->payload,
			   pool->slots[cur].next);

		cur = pool->slots[cur].next;
	}
}

void dump_free(struct PacketPool *pool)
{
	int cur = pool->free_head;

	printf("free slots: ");

	while (cur != NIL) {
		printf("%d", cur);
		cur = pool->slots[cur].next;

		if (cur != NIL)
			printf(" -> ");
	}

	printf("\n");
}

int main(void)
{
	PacketPool pool;
	pool_init(&pool);

	int a = pool_alloc(&pool);
	int b = pool_alloc(&pool);
	int c = pool_alloc(&pool);

	if (a == NIL || b == NIL || c == NIL) {
		dprintf(STDERR_FILENO, "pool_alloc failed\n");
		return 1;
	}

	packet_set(&pool, a, 100, "arp request");
	packet_set(&pool, b, 101, "ipv4 packet");
	packet_set(&pool, c, 102, "tcp segment");

	dump_active(&pool);
	dump_free(&pool);

	printf("\nfreeing slot %d\n\n", b);

	if (pool_free(&pool, b) != 0) {
		dprintf(STDERR_FILENO, "pool_free failed\n");
		return 1;
	}

	dump_active(&pool);
	dump_free(&pool);

	return 0;
}
