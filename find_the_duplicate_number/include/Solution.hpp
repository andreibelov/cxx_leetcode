/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:02:55 by abelov            #+#    #+#             */
/*   Updated: 2026/04/29 15:02:55 by abelov           ###   ########.fr       */
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
 * 287. Find the Duplicate Number
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * Given an array of integers nums containing n + 1 integers where each
 * integer is in the range [1, n] inclusive.
 *
 * There is only one repeated number in nums, return this repeated number.
 * You must solve the problem without modifying the array nums and using
 * only constant extra space.
 *
 * Constraints:
 * 	1 <= n <= 10^5
 * 	nums.length == n + 1
 * 	1 <= nums[i] <= n
 * 	All the integers in nums appear only once except for precisely one
 * 	integer which appears two or more times.
 *
 * Follow up:
 * 	How can we prove that at least one duplicate number must exist in nums?
 * 	Can you solve the problem in linear runtime complexity?
 *
 */
class Solution {
public:
	int findDuplicate(std::vector<int>& nums);
	int findDuplicate2(std::vector<int> &nums);
};

#endif //SOLUTION_HPP
