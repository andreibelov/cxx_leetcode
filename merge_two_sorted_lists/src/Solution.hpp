/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:49:48 by abelov            #+#    #+#             */
/*   Updated: 2025/02/28 14:49:48 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>
#include <tuple>

class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
	};
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
	 *
	 * Constraints:
	 * 	The number of nodes in both lists is in the range [0, 50].
	 * 	-100 <= Node.val <= 100
	 * 	Both list1 and list2 are sorted in non-decreasing order.
	 */
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
	ListNode* mergeTwoListsRec(ListNode* list1, ListNode* list2);
};

#endif //SOLUTION_HPP
