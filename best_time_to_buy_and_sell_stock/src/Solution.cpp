/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:45:52 by abelov            #+#    #+#             */
/*   Updated: 2025/08/18 22:45:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include <span>
#include "Solution.hpp"

/**
 * 121. Best Time to Buy and Sell Stock
 *
 * Return the maximum profit you can achieve from this transaction.
 * If you cannot achieve any profit, return 0.
 * @param prices
 * @return
 */
__attribute__((optimize("O3"),target("no-sse,no-avx")))
int Solution::maxProfit(std::vector<int>& prices)
{
	int min = prices.front();
	int maxProfit = 0;

//	for (int current : (std::span<int>){prices.begin() + 1, prices.end()}) // C-style trick - braced aggregate construction (std::span<int>){...}
//	for (int current : std::span<int>(prices.begin() + 1, prices.end())) // Lower-level, equivalent
	for (int current : std::span(prices).subspan(1)) // Clearer, higher-level:
	{
		maxProfit = MAX(current - min, maxProfit);
		min = MIN(min, current);
	}
	return (maxProfit);
}
