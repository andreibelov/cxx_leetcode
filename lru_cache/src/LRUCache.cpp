/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LRUCache.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:06:10 by abelov            #+#    #+#             */
/*   Updated: 2025/03/03 23:06:11 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LRUCache.hpp"

/**
 * 146. LRU Cache
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 *
 * @see: https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU
 *
 * @param capacity
 */
LRUCache::LRUCache(int capacity)
	: head(new Node()),
	tail(new Node()),
	capacity(capacity),
	currentSize(0)
{
	head->next = tail;
	tail->prev = head;
}

int LRUCache::get(int key)
{
	if (cache.count(key) == 0U) return -1;
	Node *node = cache[key];
	promoteNode(node); // Move node to head to mark as recently used
	return node->value;
}

void LRUCache::put(int key, int value)
{
	if (cache.count(key) != 0U)
	{
		Node *node = cache[key];
		node->value = value;
		promoteNode(node); // Move node to head as it's recently used
	}
	else  // Key not found, need to insert a new node
	{
		Node *node = new Node(key, value);
		cache[key] = node;
		addNode(node);
		// If over capacity, remove the least recently used item
		if (++currentSize > capacity)
		{
			node = removeTail();
			cache.erase(node->key); // Remove from the cache map
			delete node;
			--currentSize;
		}
	}
}

Node *LRUCache::removeTail()
{
	Node *node = tail->prev;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	return node;
}

void LRUCache::addNode(Node *node)
{
	node->next = head->next;
	node->prev = head;
	head->next->prev = node;
	head->next = node;
}

void LRUCache::promoteNode(Node *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	addNode(node);
}
