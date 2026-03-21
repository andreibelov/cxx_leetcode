/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 12:04:02 by abelov            #+#    #+#             */
/*   Updated: 2026/03/21 12:04:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 45. Jump Game II
 *
 * You are given a 0-indexed array of integers nums of length n.
 * You are initially positioned at index 0.
 *
 * Return the minimum number of jumps to reach index n - 1.
 * The test cases are generated such that you can reach index n - 1.
 */
int Solution::jump(std::vector<int>& nums)
{
	int ans = 0;
	int last = 0;
	int mx = 0;

	for (int i = 0; i < (int)(nums.size() - 1); ++i) {
		mx = std::max(mx, i + nums[i]);
		if (i == last) {
			ans++;
			last = mx;
		}
	}
	return ans;
}
