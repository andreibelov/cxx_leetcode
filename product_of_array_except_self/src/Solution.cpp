/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:22:24 by abelov            #+#    #+#             */
/*   Updated: 2026/03/25 00:22:24 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 238. Product of Array Except Self
 *
 * Given an integer array nums, return an array answer such that answer[i]
 * is equal to the product of all the elements of nums except nums[i].
 *
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * Write an algorithm that runs in O(n) time and without using the division operation.
 *
 */
std::vector<int> Solution::productExceptSelf(std::vector<int>& nums)
{
	std::size_t numsSize = nums.size();
	std::vector<int> products(numsSize);
	int	product = 1;

	for (std::size_t i = 0; i < numsSize; ++i) {
		products[i] = product;
		product *=  nums[i];
	}
	product = 1;
	while ((numsSize--) != 0U)
	{
		products[numsSize] *= product;
		product *=  nums[numsSize];
	}
	return products;
}
