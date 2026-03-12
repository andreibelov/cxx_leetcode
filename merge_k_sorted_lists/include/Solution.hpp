/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:15:55 by abelov            #+#    #+#             */
/*   Updated: 2026/03/12 15:15:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

class Solution {
public:
	struct ListNode {
		int		  val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
	};
	ListNode *mergeKLists(std::vector<ListNode *> &lists);
};

#endif //SOLUTION_HPP
