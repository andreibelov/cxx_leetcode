/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:45:37 by abelov            #+#    #+#             */
/*   Updated: 2025/08/17 00:45:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

typedef struct s_input
{
	std::vector<int> nums;
	std::vector<int> expected;
} Input;

int ft_do_test(Input *input)
{
	std::vector<int> &result = input->nums;
	int check_val;
	int resultSize;

	Solution sol;
	resultSize = sol.removeDuplicatesFast(input->nums);
	check_val = (int)input->expected.size() == resultSize;
	if (!check_val)
	{
		std::cout << "got array of size [\"" << result.size()
				  << "\"] whilst [\"" << input->expected.size()
				  << "\"] was to be expected" << std::endl;
	}
	else if ((check_val = std::equal(result.begin(), result.begin() + resultSize,
									 input->expected.begin())) != 1)
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
			.nums = {1,1,1,2,2,3},
			.expected = {1,1,2,2,3}
		},
		{
			.nums = {0,0,1,1,1,1,2,3,3},
			.expected = {0,0,1,1,2,3,3}
		},
	});

	for (Input in: inputs)
		ft_do_test(&in);

	return (EXIT_SUCCESS);
}
