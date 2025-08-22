/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 01:54:27 by abelov            #+#    #+#             */
/*   Updated: 2025/08/17 01:54:27 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

class Solution {
public:
	/**
	 * 169. Majority Element
	 *
	 * Given an array nums of size n, return the majority element.
	 * The majority element is the element that appears more than ⌊n / 2⌋ times.
	 * You may assume that the majority element always exists in the array.
	 *
	 * Constraints:
	 * 	n == nums.length
	 * 	1 <= n <= 5 * 10^4
	 * 	-10^9 <= nums[i] <= 10^9
	 * @param nums
	 * @return
	 */
	int majorityElement(std::vector<int>& nums);
};
