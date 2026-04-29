/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:45:26 by abelov            #+#    #+#             */
/*   Updated: 2026/04/27 13:45:26 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

/**
 * 141. Linked List Cycle
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 *
 * There is a cycle in a linked list if there is some node in the list that can be reached
 * again by continuously following the next pointer.
 * Internally, pos is used to denote the index of the node that tail's next pointer
 * is connected to. Note that pos is not passed as a parameter.
 *
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 *
 * Constraints:
 * 		The number of the nodes in the list is in the range [0, 10^4].
 * 		-10^5 <= Node.val <= 10^5
 * 		pos is -1 or a valid index in the linked-list.

 */
class Solution {
public:
	struct ListNode {
	    int val;
	    ListNode *next;
	    ListNode(int x) : val(x), next(NULL) {}
	};
	bool hasCycle(ListNode *head);
	bool hasCycle2(ListNode *head);
};

#endif //SOLUTION_HPP
