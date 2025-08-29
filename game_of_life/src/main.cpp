/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 01:22:08 by abelov            #+#    #+#             */
/*   Updated: 2025/08/26 01:22:08 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Case = struct s_input
{
	std::vector<std::vector<int>> board;
	std::vector<std::vector<int>> expected;
};

int ft_do_test(Case &input)
{
	std::vector<std::vector<int>>	&result = input.board;
	bool check_val = false;

	Solution sol;
	sol.gameOfLife(input.board);
	check_val = input.expected.size() == result.size();
	if (!check_val)	{
		std::cout << "got array of size [\"" << result.size()
				  << "\"] whilst [\"" << input.expected.size()
				  << "\"] was to be expected"
				  << std::endl;
	}
	else {
		check_val = (input.expected == result);
		if (!check_val)
			std::cout << "got " << result
					  << " whilst " << input.expected
					  << " was to be expected"
					  << std::endl;
	}
	check(check_val);
	return (0);
}

int main()
{
	std::array<Case, 5>	inputs = std::to_array<Case>(
	{
		{
			.board = {
				{0,1,0},
				{0,0,1},
				{1,1,1},
				{0,0,0}
			},
			.expected = {
				{0,0,0},
				{1,0,1},
				{0,1,1},
				{0,1,0}
			}
		},
		{
			.board = {
				{1,1},
				{1,0}
			},
			.expected = {
				{1,1},
				{1,1}
			}
		},
		// Still life block should remain unchanged
		{
			.board = {
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0}
			},
			.expected = {
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0}
			}
		},
		// Blinker oscillator period 2
		{
			.board = {
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,1,1,1,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			},
			.expected = {
				{0,0,0,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0},
				{0,0,0,0,0}
			}
		},
		// Edge handling
		{
			.board = { {1} },
			.expected = { {0} }
		}
	});

	for (Case& test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
