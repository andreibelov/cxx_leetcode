/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:22:24 by abelov            #+#    #+#             */
/*   Updated: 2026/03/25 00:22:24 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

typedef struct s_input
{
	std::vector<int> nums;
	std::vector<int> expected;
}	Input;

int ft_do_test(Input *input)
{
	std::vector<int> result;
	bool check_val;

	Solution sol;
	result = sol.productExceptSelf(input->nums);
	check_val = (input->expected.size() == result.size());
	if (!check_val)
	{
		std::cout << "got array of size [\"" << result.size()
				  << "\"] whilst [\"" << input->expected.size()
				  << "\"] was to be expected" << std::endl;
	}
	else if (!(check_val = std::equal(result.begin(), result.end(), input->expected.begin())))
	{
		check(check_val);
		std::cout << "got " << result << " whilst " << input->expected
				  << " was to be expected" << std::endl;
	}
	else
		check(check_val);
	return (0);
}

int main()
{
	auto	inputs = std::to_array<Input>(
		{
			{
				.nums = {1,2,3,4},
				.expected = {24,12,8,6}
			},
			{
				.nums = {-1,1,0,-3,3},
				.expected = {0,0,9,0,0}
			},
		});

	for (Input in: inputs)
		ft_do_test(&in);

	return (EXIT_SUCCESS);
}

