/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:44:25 by abelov            #+#    #+#             */
/*   Updated: 2025/02/27 23:44:26 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 88. Merge Sorted Array
 *
 *
 * @param nums1 has a length of m + n, where the first m elements denote
 * 			the elements that should be merged, and the last n elements
 * 			are set to 0 and should be ignored.
 * @param m
 * @param nums2 has a length of n
 * @param n
 */
void
Solution::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
	int r = m-- + n-- - 1;

	while (n >= 0)
		nums1[r--] = (m >= 0 && nums1[m] > nums2[n]) ? nums1[m--] : nums2[n--];
}
