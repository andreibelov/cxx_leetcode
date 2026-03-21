/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 12:04:02 by abelov            #+#    #+#             */
/*   Updated: 2026/03/21 12:04:02 by abelov           ###   ########.fr       */
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
 * 45. Jump Game II
 *
 * You are given a 0-indexed array of integers nums of length n.
 * You are initially positioned at index 0.
 *
 * Each element nums[i] represents the maximum length of a forward
 * jump from index i. In other words, if you are at index i,
 * you can jump to any index (i + j) where:
 * 		0 <= j <= nums[i] and
 * 		i + j < n
 * Return the minimum number of jumps to reach index n - 1.
 * The test cases are generated such that you can reach index n - 1.
 * /																																																			 */
class Solution {
public:
	int jump(std::vector<int>& nums);
};

#endif //SOLUTION_HPP
