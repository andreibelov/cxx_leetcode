/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:07:25 by abelov            #+#    #+#             */
/*   Updated: 2025/08/15 19:07:25 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 27. Remove Element
 * std::remove from <algorithm> doesn’t actually shrink the vector.
 * It just moves all elements not equal to val to the front,
 * returning an iterator to the new logical end.
 * @param nums
 * @param val
 * @return
 */
int Solution::removeElement(std::vector<int> &nums, int val)
{
	nums.erase(std::remove(nums.begin(), nums.end(), val),nums.end());
	return (int)nums.size();
}
