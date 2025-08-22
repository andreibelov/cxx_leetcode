/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:23:27 by abelov            #+#    #+#             */
/*   Updated: 2025/04/24 15:23:28 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>
#include <algorithm>

class Solution
{
public:
	/**
	 * 189. Rotate Array
	 *
	 * Given an integer array nums, rotate the array to the right by k steps,
	 * where k is non-negative.
	 *
	 * Constraints:
	 * 	1 <= nums.length <= 10^5
	 * 	-2^31 <= nums[i] <= 2^31 - 1
	 * 	0 <= k <= 10^5
	 */
	void rotate(std::vector<int>& nums, int k);
};

#endif //SOLUTION_HPP
