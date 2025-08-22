/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:51:14 by abelov            #+#    #+#             */
/*   Updated: 2025/02/28 14:51:14 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 21. Merge Two Sorted Lists
 *
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists into one sorted list.
 * The list should be made by splicing together the nodes
 * of the first two lists.
 *
 * @param list1
 * @param list2
 * @return the head of the merged linked list.
 */
Solution::ListNode *Solution::mergeTwoLists(ListNode *list1, ListNode *list2)
{
	if (list1 == nullptr) return list2;
	if (list2 == nullptr) return list1;

	ListNode head;
	ListNode *tail = &head; // Pointer to build the merged list

	while ((list1 != nullptr) && (list2 != nullptr))
	{
		if (list1->val > list2->val)
		{
			tail->next = list2;
			list2 = list2->next;
		}
		else
		{
			tail->next = list1;
			list1 = list1->next;
		}
		tail = tail->next;
	}

	if (list1 != nullptr) tail->next = list1;
	else tail->next = list2;
	return (head.next);
}

Solution::ListNode *Solution::mergeTwoListsRec(ListNode *list1, ListNode *list2)
{
	if (list1 == nullptr) return list2;
	if (list2 == nullptr) return list1;

	if (list1->val <= list2->val)
	{
		list1->next = mergeTwoListsRec(list1->next, list2);
		return (list1);
	}
	list2->next = mergeTwoListsRec(list1, list2->next);
	return (list2);
}
