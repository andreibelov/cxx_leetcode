/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 01:54:27 by abelov            #+#    #+#             */
/*   Updated: 2025/08/17 01:54:27 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unordered_map>
#include <functional>
#include "Solution.hpp"

/**
 * 169. Majority Element
 *
 * Given an array nums of size n, return the majority element.
 *
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 * @param nums
 * @param val
 * @return the majority element
 */
int Solution::majorityElement(std::vector<int>& nums)
{
	if (nums.size() == 1)
		return static_cast<int>(nums[0]);

	int maj = 0;
	std::unordered_map<int,int>	tbl;

	for (int num: nums)
		if (++tbl[num] > tbl[maj])
			maj = num;
	return maj;
}
