/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 01:26:47 by abelov            #+#    #+#             */
/*   Updated: 2025/08/20 01:26:47 by abelov           ###   ########.fr       */
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
	 * 123. Best Time to Buy and Sell Stock III
	 *
	 * @param prices
	 * 	Constraints:
	 * 		1 <= prices.length <= 10^5
	 * 		0 <= prices[i] <= 10^5
	 * @return Find and return the maximum profit you can achieve.
	 */
	int maxProfit(std::vector<int> &prices);
};

