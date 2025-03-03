/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LRUCache.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:05:33 by abelov            #+#    #+#             */
/*   Updated: 2025/03/03 23:05:34 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef LRUCACHE_HPP
#define LRUCACHE_HPP

#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include <unordered_map>

struct Node
{
	int key;
	int value;
	Node *prev;
	Node *next;

	// Default constructor
	Node()
		: key(0), value(0), prev(nullptr), next(nullptr) {}

	// A node with a specified key and value
	Node(int key, int value)
		: key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
	std::unordered_map<int, Node*>	cache;
	Node*	head;
	Node*	tail;
	int		capacity;
	int		currentSize;
	Node*	removeTail();
	void	addNode(Node* node);
	void	promoteNode(Node* node);

public:
	LRUCache(int capacity);
	int get(int key);
	void put(int key, int value);
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //LRUCACHE_HPP
