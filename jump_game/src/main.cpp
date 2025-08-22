/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:27:17 by abelov            #+#    #+#             */
/*   Updated: 2025/08/20 11:27:17 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<int> nums;
	bool expected;
};

int ft_do_test(Input &input)
{
	bool check_val = false;
	bool result = false;

	Solution sol;
	result = sol.canJump(input.nums);
	check_val = (input.expected == result);
	if (!check_val)
	{
		std::cout << "got [\"" << (result ? "true" : "false")
				  << "\"] whilst [\"" << (input.expected ? "true" : "false")
				  << "\"] was to be expected" << std::endl;
	}
	check(check_val);
	return (0);
}

int main()
{
	auto inputs = std::to_array<Input>(
		{
			{
				.nums = {2,3,1,1,4},
				.expected = true
			},
			{
				.nums = {3,2,1,0,4},
				.expected = false
			},

		}
	);

	for (Input test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
