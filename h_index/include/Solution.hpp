/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:48:08 by abelov            #+#    #+#             */
/*   Updated: 2026/03/22 22:48:08 by abelov           ###   ########.fr       */
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
 * 274. H-Index
 *
 * Given an array of integers citations where citations[i] is the number
 * of citations a researcher received for their ith paper,
 * return the researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia:
 * 	The h-index is defined as the maximum value of h such that the given researcher
 * 	has published at least h papers that have each been cited at least h times.
 */
class Solution {
public:
	int hIndex(std::vector<int>& citations);
};

#endif //SOLUTION_HPP
