/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:45:37 by abelov            #+#    #+#             */
/*   Updated: 2025/08/19 15:45:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

struct Solution {

	/**
	 * 122. Best Time to Buy and Sell Stock II
	 *
	 * Constraints:
	 * 	1 <= prices.length <= 3 * 10^4
	 * 	0 <= prices[i] <= 10^4
	 *
	 * @param prices
	 * @return Find and return the maximum profit you can achieve.
	 */
	int maxProfit(std::vector<int> &prices);
};
