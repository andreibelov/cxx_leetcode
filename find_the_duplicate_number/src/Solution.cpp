/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:02:55 by abelov            #+#    #+#             */
/*   Updated: 2026/04/29 15:02:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 287. Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * Given an array of integers nums containing n + 1 integers where each
 * integer is in the range [1, n] inclusive.
 *
 * There is only one repeated number in nums, return this repeated number.
 */
int Solution::findDuplicate(std::vector<int>& nums)
{
		int n = nums.size() - 1;

		int left = 1;
		int right = n;
		int firstTrueIndex = -1;

		while (left <= right) {
			int mid = left + ((right - left) / 2);

			int count = 0;
			for (int num : nums) if (num <= mid) count++;

			if (count > mid) {
				firstTrueIndex = mid;
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		return firstTrueIndex;
}


/**
 * https://medium.com/%40leetsswift/leetcode-287-find-the-duplicate-number-7e77eac6dc54
 * Mental model: array defines a graph where each index points to nums[index]
 *
 * The trick is: the array is being treated as a linked list:
 * 	0 -> nums[0] = 1
 * 	1 -> nums[1] = 3
 * 	3 -> nums[3] = 2
 * 	2 -> nums[2] = 4
 * 	4 -> nums[4] = 2
 *
 * So the path is:
 * 	0 -> 1 -> 3 -> 2 -> 4
 * 	               ^    |
 * 	               |____|
 * @param nums
 * @return
 */
int Solution::findDuplicate2(std::vector<int>& nums)
{
	int slow = nums[0];
	int fast = nums[0];

	// Step 1: detect cycle
	do {
		slow = nums[slow];
		fast = nums[nums[fast]];
	} while (slow != fast);

	// Step 2: find cycle's entry point
	slow = nums[0];

	while (slow != fast) {
		slow = nums[slow];
		fast = nums[fast];
	}

	return slow;
}
