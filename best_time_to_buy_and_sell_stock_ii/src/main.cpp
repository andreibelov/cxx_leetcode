/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:45:37 by abelov            #+#    #+#             */
/*   Updated: 2025/08/19 15:45:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<int> nums;
	int expected;
};

int ft_do_test(Input &input)
{
	int check_val = 0;
	int	result = 0;

	Solution sol;
	result = sol.maxProfit(input.nums);
	check_val = static_cast<int>(input.expected == result);
	if (check_val == 0)
	{
		std::cout << "got [\"" << result << "\"] whilst [\"" << input.expected
				  << "\"] was to be expected" << std::endl;
	}
	check(check_val != 0);
	return (0);
}

int main()
{
	auto inputs = std::to_array<Input>(
		{
			{
				.nums = {7,1,5,3,6,4},
				.expected = 7
			},
			{
				.nums = {1,2,3,4,5},
				.expected = 4
			},
			{
				.nums = {7,6,4,3,1},
				.expected = 0
			},
		}
	);

	for (Input test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}

