/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:27:17 by abelov            #+#    #+#             */
/*   Updated: 2025/08/20 11:27:17 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include <algorithm>
#include <ranges>
#include <vector>
#include "Solution.hpp"

using std::views::iota;
using std::views::zip;

/**
 * 55. Jump Game
 *
 * You are given an integer array nums. You are initially positioned at the
 * array's first index, and each element in the array represents your
 * maximum jump length at that position.
 *
 * @param nums
 * 	Constraints:
 * 		1 <= nums.length <= 10^4
 * 		0 <= nums[i] <= 10^5
 * @return true if you can reach the last index, or false otherwise.
 */
__attribute__((optimize("O3"),target("no-sse,no-avx")))
__attribute__((optimize("inline-functions-called-once")))
__attribute__((no_sanitize("all")))
bool Solution::canJump(std::vector<int>& nums)
{
	size_t	maxReachable = 0;
	auto	range = zip(iota(size_t{0}), nums);

	for (std::tuple<size_t, int&> tup : range) {
		size_t	i = std::get<0>(tup);
		size_t cand = i + (size_t)(std::get<1>(tup));

		if (maxReachable < i)
			return (false);
		maxReachable = std::max(maxReachable, cand);
		if (maxReachable >= nums.size() - 1)
			return true;
	}
	return (true);
}
