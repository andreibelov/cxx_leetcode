/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 01:24:06 by abelov            #+#    #+#             */
/*   Updated: 2025/09/19 01:24:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include <numeric>

/**
 * 322. Coin Change
 *
 * @param denoms
 * @param amount
 * @return
 */
int Solution::coinChange(std::vector<int>& coins, int amount)
{
	int fewest = -1;
	enum e_state { LEFT = 0, RIGHT, SELF }; // NOLINT(*-enum-size)

	std::vector<std::vector<int>> out;

	struct Frame { std::vector<int> denominations; int amount; std::vector<int> coins; e_state state;};

	std::vector<Frame> stack;
	stack.reserve(2UL * coins.size());

	stack.push_back(Frame{
		.denominations = coins,
		.amount = amount,
		.coins = std::vector<int>(),
		.state = LEFT
	});

	while (!stack.empty()) {
		Frame fr = stack.back();
		stack.pop_back();

		if (fr.amount == 0) {
			out.push_back(fr.coins);
			continue;
		}
		if (fr.amount < 0) {
			continue;
		}

		switch (fr.state)
		{
			case LEFT: {
				fr.state = RIGHT;
				stack.push_back(fr);
				if (!fr.denominations.empty() && fr.amount - fr.denominations.back() >= 0) {
					fr.coins.push_back(fr.denominations.back());
					stack.push_back(Frame{
						.denominations = fr.denominations,
						.amount = fr.amount - fr.denominations.back(),
						.coins = fr.coins,
						.state = LEFT
					});
				}
				[[fallthrough]];
			}
			case RIGHT: {
				fr.state = SELF;
				stack.push_back(fr);
				fr.denominations.pop_back();
				if (!fr.denominations.empty()) {
					stack.push_back(Frame{
						.denominations = fr.denominations,
						.amount = fr.amount,
						.coins = fr.coins,
						.state = LEFT
					});
				}
				[[fallthrough]];
			}
			case SELF:
				break;
		}

	}

	for (const std::vector<int>& vec : out)
	{
		if (vec.size() < (size_t)fewest)
			fewest = (int)vec.size();
	}

	return fewest;
}
