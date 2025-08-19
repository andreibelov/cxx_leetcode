/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:45:37 by abelov            #+#    #+#             */
/*   Updated: 2025/08/17 00:45:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unordered_map>
#include <functional>
#include "Solution.hpp"

/**
 * 80. Remove Duplicates from Sorted Array II
 *
 * Given an integer array nums sorted in non-decreasing order, remove some
 * duplicates in-place such that each unique element appears at most twice.
 * The relative order of the elements should be kept the same.
 *
 * What is the best way to use a HashMap in C++?
 * @see https://stackoverflow.com/questions/3578083/#3578247
 * @param nums
 * @return
 */
int Solution::removeDuplicates(std::vector<int>& nums)
{
	if (nums.size() <= 2)
		return static_cast<int>(nums.size());

	std::unordered_map<int,int>	tbl;
	std::vector<int>::iterator	new_end;
	std::function<bool(int)>	func;

	func = [&tbl](int num) -> int { return (++tbl[num] > 2); };
	new_end = std::remove_if(nums.begin(), nums.end(), func);
	nums.erase(new_end, nums.end());
	nums.shrink_to_fit();
	return static_cast<int>(new_end - nums.begin());
}

int Solution::removeDuplicatesFaster(std::vector<int>& nums)
{
	if (nums.size() <= 2)
		return static_cast<int>(nums.size());

	std::unordered_map<int,int>	tbl;
	std::vector<int>::iterator	new_end;
	std::function<bool(int)>	func;

	func = [&tbl](int num) -> int { return (++tbl[num] > 2); };
	new_end = std::remove_if(nums.begin(), nums.end(), func);
	return static_cast<int>(new_end - nums.begin());
}

int Solution::removeDuplicatesFast(std::vector<int>& nums)
{
	if (nums.size() <= 2)
		return static_cast<int>(nums.size());

	int i = 2;
	for (int j = 2; j < static_cast<int>(nums.size()); ++j)
		if (nums[j] != nums[i - 2])
			nums[i++] = nums[j];
	return i;
}
