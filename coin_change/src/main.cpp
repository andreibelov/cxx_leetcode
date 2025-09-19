/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 01:24:06 by abelov            #+#    #+#             */
/*   Updated: 2025/09/19 01:24:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<int>	coins;
	int					amount;
	int					expected;
};


int ft_do_test(Input &input)
{
	int result = 0;
	bool check_val = false;

	Solution sol;
	result = sol.coinChange(input.coins, input.amount);
	check_val = (input.expected == result);
	if (!check_val)
	{
		std::cout << "Value mismatch: got [\"" << result
				  << "\"] whilst [\"" << input.expected
				  << "\"] was to be expected" << std::endl;
	}
	check(check_val);
	return (0);
}

int main()
{
	auto	inputs = std::to_array<Input>(
		{
			{
				.coins = {1,2,5},
				.amount = 11,
				.expected = 3
			},
			{
				.coins = {2},
				.amount = 3,
				.expected = -1
			},
			{
				.coins = {1},
				.amount = 0,
				.expected = 0
			},
			{
				.coins = {1,2147483647},
				.amount = 2,
				.expected = 2
			},
			{
				.coins = {3,7,405,436},
				.amount = 8839,
				.expected = 2
			},
		});

	for (Input& test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
