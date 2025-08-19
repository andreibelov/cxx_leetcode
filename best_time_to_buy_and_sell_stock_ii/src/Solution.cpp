/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:45:37 by abelov            #+#    #+#             */
/*   Updated: 2025/08/19 15:45:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <ranges>
#include "Solution.hpp"

/**
 * 122. Best Time to Buy and Sell Stock II
 *
 * You are given an integer array prices where prices[i] is the price
 * of a given stock on the ith day.
 * On each day, you may decide to buy and/or sell the stock.
 * You can only hold at most one share of the stock at any time.
 * However, you can buy it then immediately sell it on the same day.
 *
 * @param prices
 * @param val
 * @return maximum profit you can achieve.
 */
int Solution::maxProfit(std::vector<int> &prices)
{
	if (prices.size() < 2) return 0;
	int accumulatedProfit = 0;

	for (auto [prev, curr] : std::views::pairwise(prices)) {
		if (prev < curr)
			accumulatedProfit += curr - prev;
	}
	return accumulatedProfit;
}
