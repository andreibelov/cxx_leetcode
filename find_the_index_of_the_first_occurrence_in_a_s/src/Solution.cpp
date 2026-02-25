/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 01:11:08 by abelov            #+#    #+#             */
/*   Updated: 2026/02/25 01:11:08 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 28. Find the Index of the First Occurrence in a String
 *
 * Given two strings needle and haystack
 * @param haystack
 * @param needle
 * @return the index of the first occurrence
 * of needle in haystack, or -1 if needle is not part of haystack.
 */
int Solution::strStr(const std::string& haystack, const std::string& needle) {
	unsigned long idx = haystack.find(needle);
	if (idx == std::string::npos)
		return -1;
	return (int)idx;
}
