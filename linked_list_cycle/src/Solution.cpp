/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:45:26 by abelov            #+#    #+#             */
/*   Updated: 2026/04/27 13:45:26 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include <unordered_set>

bool Solution::hasCycle(ListNode *head)
{
		std::unordered_set<ListNode *> visitedNodes;

		ListNode* next = nullptr;
		while (head != nullptr)
		{
			next = head->next;
			visitedNodes.insert(head);
			if (visitedNodes.contains(next))
				goto has_cycle;
			head = next;
		}
		return false;
	has_cycle:
		return true;
}

/**
 * Using Floyd's Cycle Detection Algorithm (Tortoise and Hare)
 * https://en.wikipedia.org/wiki/Cycle_detection
 * @param head
 * @return
 */
bool Solution::hasCycle2(ListNode *head)
{
	if(head == nullptr || head->next == nullptr)
		return false;

	ListNode *hare	   = head->next;
	ListNode *tortoise = head;
	while(hare != tortoise)
	{
		if (hare->next == nullptr || hare->next->next == nullptr)
			return false;
		hare	 = hare->next->next;
		tortoise = tortoise->next;
	}
	return true;
}
