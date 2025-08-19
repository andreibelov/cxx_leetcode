/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:45:52 by abelov            #+#    #+#             */
/*   Updated: 2025/08/18 22:45:52 by abelov           ###   ########.fr       */
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
	 * Constraints:
	 * 1 <= prices.length <= 10^5
	 * 0 <= prices[i] <= 10^4
	 * @param prices
	 * @return
	 */
	int maxProfit(std::vector<int>& prices);
};
