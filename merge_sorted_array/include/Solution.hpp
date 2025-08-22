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

#pragma once
#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

class Solution {
public:
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
	 *
	 * Constraints:
	 * 	nums1.length == m + n
	 * 	nums2.length == n
	 * 	0 <= m, n <= 200
	 * 	1 <= m + n <= 200
	 * 	-10^9 <= nums1[i], nums2[j] <= 10^9
	 */
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
};

#endif //SOLUTION_HPP
