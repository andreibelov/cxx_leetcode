/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 01:26:47 by abelov            #+#    #+#             */
/*   Updated: 2025/08/20 01:26:47 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include "Solution.hpp"

/**
 * 123. Best Time to Buy and Sell Stock III
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the ith day.
 *
 * Note: You may not engage in multiple transactions simultaneously
 * 	(i.e., you must sell the stock before you buy again).
 *
 * @param prices
 * @return Find the maximum profit you can achieve.
 * You may complete at most two transactions.
 */
int Solution::maxProfit(std::vector<int> &prices)
{
	int buyFirst = -prices[0];
	int buySecond = buyFirst;
	int sellFirst = 0;
	int sellSecond = 0;

	for (int currentPrice : prices)
	{
		buyFirst = MAX(buyFirst, -currentPrice);
		sellFirst = MAX(sellFirst, buyFirst + currentPrice);
		buySecond = MAX(buySecond, sellFirst - currentPrice);
		sellSecond = MAX(sellSecond, buySecond + currentPrice);
	}

	return sellSecond;
}
