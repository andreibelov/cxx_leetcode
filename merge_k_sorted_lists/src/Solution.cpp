/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:15:55 by abelov            #+#    #+#             */
/*   Updated: 2026/03/12 15:15:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include <queue>

struct CompareListNode {
	bool operator()(Solution::ListNode *a, Solution::ListNode *b) const {
		return a->val > b->val;
	}
};

using priority_queue = std::priority_queue<Solution::ListNode *,
										   std::vector<Solution::ListNode *>,
										       CompareListNode>;

/**
 * 23. Merge k Sorted Lists
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * @param lists
 * @return
 */
Solution::ListNode *Solution::mergeKLists(std::vector<Solution::ListNode *> &lists) {

	::priority_queue pq;
	ListNode* dummyHead = new ListNode(0);
	ListNode* current = dummyHead;

	for (ListNode *node: lists)
		if (node) pq.push(node);

	while (!pq.empty()) {
		ListNode* minNode = pq.top();
		pq.pop();

		if (minNode->next != nullptr)
			pq.push(minNode->next);

		current->next = minNode;
		current = current->next;
	}

	ListNode *next = dummyHead->next;

	delete dummyHead;
	return next;
}
