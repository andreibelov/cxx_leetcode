/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 23:43:56 by abelov            #+#    #+#             */
/*   Updated: 2026/05/07 23:43:56 by abelov           ###   ########.fr       */
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

/**
 * 131. Palindrome Partitioning
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 *
 * Constraints:
 * 	1 <= s.length <= 16
 * 	s contains only lowercase English letters.
 *
 * @see: https://leetcode.com/problems/palindrome-partitioning/
 */
class Solution {
public:
	std::vector<std::vector<std::string>> partition(std::string s);
};

#endif //SOLUTION_HPP
