/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:02:07 by abelov            #+#    #+#             */
/*   Updated: 2025/08/19 18:02:07 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<int>	nums;
	int					val;
	int					expected;
};

int ft_do_test(Input &input)
{
	int		result = 0;
	bool	check_val = false;

	Solution sol;
	result = sol.maxProfit(input.nums, input.val);
	check_val = (input.expected == result);
	if (!check_val)
	{
		std::cout << "got [\"" << result << "\"] whilst [\"" << input.expected
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
				.nums = {1,3,2,8,4,9},
				.val = 2,
				.expected = 8
			},
			{
				.nums = {1,3,7,5,10,3},
				.val = 3,
				.expected = 6
			},
		}
	);

	for (Input test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
