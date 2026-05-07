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
#include <stdlib.h>
#include <string.h>

#define POOL_CAP 8
#define PAYLOAD_CAP 32

struct Packet {
	int		id;
	size_t	len;
	char	payload[PAYLOAD_CAP];
};

union Slot {
	struct Packet packet;
	union Slot *next_free;
};

struct PacketPool {
	union Slot slots[POOL_CAP];
	union Slot *free_head;
};

void pool_init(struct PacketPool *pool)
{
	size_t i = -1;

	while (++i + 1 < POOL_CAP)
		pool->slots[i].next_free = &pool->slots[i + 1];

	pool->slots[POOL_CAP - 1].next_free = NULL;
	pool->free_head = &pool->slots[0];
}

struct Packet *pool_alloc(struct PacketPool *pool)
{
	union Slot *slot;

	if (pool->free_head == NULL)
		return NULL;

	slot = pool->free_head;
	pool->free_head = slot->next_free;

	memset(&slot->packet, 0, sizeof(slot->packet));

	return &slot->packet;
}

void pool_free(struct PacketPool *pool, struct Packet *packet)
{
	union Slot *slot;

	if (packet == NULL)
		return;

	slot = (union Slot *)packet;

	slot->next_free = pool->free_head;
	pool->free_head = slot;
}

static void packet_set(struct Packet *packet, int id, const char *payload)
{
	packet->id = id;
	snprintf(packet->payload, sizeof(packet->payload), "%s", payload);
	packet->len = strlen(packet->payload);
}

/**
 * https://github.com/endurodave/C_Allocator/blob/master/main.cpp
 * https://github.com/8dcc/libpool/blob/main/examples/libpool-example.c
 * @return
 */
int main(void)
{
	struct PacketPool pool;

	pool_init(&pool);

	struct Packet *a = pool_alloc(&pool);
	struct Packet *b = pool_alloc(&pool);
	struct Packet *c = pool_alloc(&pool);


	if (a == NULL || b == NULL || c == NULL) {
		fprintf(stderr, "packet_alloc failed\n");
		return EXIT_FAILURE;
	}

	packet_set(a, 100, "arp request");
	packet_set(b, 101, "ipv4 packet");
	packet_set(c, 102, "tcp segment");

	fprintf(stdout, "%d %zu %s\n", a->id, a->len, a->payload);
	fprintf(stdout, "%d %zu %s\n", b->id, b->len, b->payload);
	fprintf(stdout, "%d %zu %s\n", c->id, c->len, c->payload);

	pool_free(&pool, b);

	b = pool_alloc(&pool);
	if (b == NULL) {
		fprintf(stderr, "packet_alloc failed\n");
		return 1;
	}

	packet_set(b, 103, "reused packet slot");

	fprintf(stdout, "%d %zu %s\n", b->id, b->len, b->payload);

	return 0;
}