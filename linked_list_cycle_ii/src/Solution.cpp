/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:53:45 by abelov            #+#    #+#             */
/*   Updated: 2026/05/07 16:53:45 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"


/**
 * 142. Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * Given the head of a linked list, return the node where the cycle begins.
 * If there is no cycle, return null.
 *
 * There is a cycle in a linked list if there is some node in the list
 * that can be reached again by continuously following the next pointer.
 *
 * Internally, pos is used to denote the index of the node that
 * tail's next pointer is connected to (0-indexed).
 * It is -1 if there is no cycle.
 *
 * Note that pos is not passed as a parameter.
 *
 * Constraints:
 * 		The number of the nodes in the list is in the range [0, 104].
 * 		-10^5 <= Node.val <= 10^5
 * 		pos is -1 or a valid index in the linked-list.
 */
Solution::ListNode *Solution::detectCycle(ListNode *head)
{
	ListNode *tortoise	= head;
	ListNode *hare		= head;

	while (hare && hare->next) {
		tortoise = tortoise->next;
		hare	 = hare->next->next;

		if (tortoise == hare) {
			tortoise = head;

			while (tortoise != hare) {
				tortoise = tortoise->next;
				hare	 = hare->next;
			}

			return tortoise;
		}
	}

	return nullptr;
}

Solution::ListNode *Solution::detectCycle2(Solution::ListNode *head)
{
	if(head == nullptr || head->next == nullptr)
		return nullptr;

	// Step 1: detect cycle
	ListNode *hare	   = head;
	ListNode *tortoise = head;

	do {
		if (hare->next == nullptr || hare->next->next == nullptr)
			return nullptr;
		hare	 = hare->next->next;
		tortoise = tortoise->next;
	} while (hare != tortoise);


	// Step 2: find cycle's entry point
	tortoise = head;

	while (hare != tortoise) {
		hare	 = hare->next;
		tortoise = tortoise->next;
	}

	return tortoise;
}
