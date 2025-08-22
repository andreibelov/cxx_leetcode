/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:23:32 by abelov            #+#    #+#             */
/*   Updated: 2025/04/24 15:23:32 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 189. Rotate Array
 *
 * Given an integer array nums, rotate the array to the right by k steps,
 * where k is non-negative.
 *
 * @param nums
 * @param k
 */
void Solution::rotate(std::vector<int> &nums, int k)
{
	int num_elements = nums.size();
	k %= num_elements; // Ensure k is within the bounds of the vector's size

	// Reverse the entire vector
	std::reverse(nums.begin(), nums.end());

	// Reverse the first k elements to restore their original order
	std::reverse(nums.begin(), nums.begin() + k);

	// Reverse the remaining elements to restore their original order
	std::reverse(nums.begin() + k, nums.end());
}
