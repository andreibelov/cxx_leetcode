/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:02:55 by abelov            #+#    #+#             */
/*   Updated: 2026/04/29 15:02:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<int> nums;
	int expected;
};

int ft_do_test(Input *input)
{
	int check_val = 0;
	int	result = 0;

	Solution sol;
	result = sol.findDuplicate(input->nums);
	check_val = static_cast<int>(input->expected == result);
	if (check_val == 0)
	{
		std::cout << "got [\"" << result << "\"] whilst [\"" << input->expected
				  << "\"] was to be expected" << std::endl;
	}
	check(check_val != 0);
	return (0);
}

int main()
{
	auto inputs = std::to_array<Input>({
		{
			.nums = {1,3,4,2,2},
			.expected = 2
		},
		{
			.nums = {3,1,3,4,2},
			.expected = 3
		},
		{
			.nums = {3,3,3,3,3},
			.expected = 3
		},
	});

	for (Input test: inputs)
		ft_do_test(&test);

	return (EXIT_SUCCESS);
}
