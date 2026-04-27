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
#include <set>

bool Solution::hasCycle(ListNode *head)
{
		std::set<ListNode *> table;

		ListNode* next = nullptr;
		while (head != nullptr)
		{
			next = head->next;
			table.insert(head);
			if (table.contains(next))
				goto has_cycle;
			head = next;
		}
		return false;
	has_cycle:
		return true;
}
