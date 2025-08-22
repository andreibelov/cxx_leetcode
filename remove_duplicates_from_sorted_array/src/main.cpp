/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:07:21 by abelov            #+#    #+#             */
/*   Updated: 2025/08/17 00:07:21 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<int> nums;
	std::vector<int> expected;
};

int ft_do_test(Input &input)
{
	std::vector<int> &result = input.nums;
	int check_val;

	Solution sol;
	sol.removeDuplicates(input.nums);
	check_val = input.expected.size() == input.nums.size();
	if (!check_val)
	{
		std::cout << "got array of size [\"" << result.size()
				  << "\"] whilst [\"" << input.expected.size()
				  << "\"] was to be expected" << std::endl;
	}
	else if ((check_val = (input.expected == input.nums)) != 1)
	{
		check(check_val);
		std::cout << "got " << result << " whilst " << input.expected
				  << " was to be expected" << std::endl;
	}
	else
		check(check_val);
	return (0);
}

int main()
{
	auto inputs = std::to_array<Input>(
	{
		{
			.nums = {1,1,2},
			.expected = {1,2}
		},
		{
			.nums = {0,0,1,1,1,2,2,3,3,4},
			.expected = {0,1,2,3,4}
		},
	});

	for (Input test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
