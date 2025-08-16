/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:07:21 by abelov            #+#    #+#             */
/*   Updated: 2025/08/17 00:07:21 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 26. Remove Duplicates from Sorted Array
 *
 * Given an integer array nums sorted in non-decreasing order, remove the
 * duplicates in-place such that each unique element appears only once.
 * The relative order of the elements should be kept the same.
 * Then return the number of unique elements in nums.
 * @param nums
 * @return
 */
int Solution::removeDuplicates(std::vector<int>& nums)
{
	nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
	return (int)nums.size();
}
