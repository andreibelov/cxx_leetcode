/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:02:07 by abelov            #+#    #+#             */
/*   Updated: 2025/08/19 18:02:07 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include "Solution.hpp"

/**
 * 714. Best Time to Buy and Sell Stock with Transaction Fee
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the ith day, and an integer fee representing a transaction fee.
 *
 * You may complete as many transactions as you like, but you need to pay the
 * transaction fee for each transaction.
 *
 * Note:
 *  You may not engage in multiple transactions simultaneously.
 *  The transaction fee is only charged once for each stock purchase and sale.
 *
 * @param prices
 * @param fee
 * @return Find the maximum profit you can achieve.
 */
int Solution::maxProfit(std::vector<int> &prices, int fee)
{
	if (prices.size() < 2) return 0;

	int cash = 0;          // max profit without holding a stock
	int hold = -prices[0]; // max profit  while  holding a stock

	for (int currentPrice : prices)
	{
		cash = MAX(cash, hold + currentPrice - fee); // sell today or do nothing
		hold = MAX(hold, cash - currentPrice);		  // buy today or do nothing
	}
	return cash;
}
