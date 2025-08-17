/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 01:54:27 by abelov            #+#    #+#             */
/*   Updated: 2025/08/17 01:54:27 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

typedef struct s_input
{
	std::vector<int> nums;
	int expected;
} Input;

int ft_do_test(Input *input)
{
	int check_val;
	int	result;

	Solution sol;
	result = sol.majorityElement(input->nums);
	check_val = (input->expected == result);
	if (!check_val)
	{
		std::cout << "got [\"" << result << "\"] whilst [\"" << input->expected
				  << "\"] was to be expected" << std::endl;
	}
	check(check_val);
	return (0);
}

int main()
{

	Input inputs[] = {
		{
			.nums = {3,2,3},
			.expected = 3
		},
		{
			.nums = {2,2,1,1,1,2,2},
			.expected = 2
		},
		{
			.nums = {5},
			.expected = 5
		},
	};

	for (Input in: inputs)
		ft_do_test(&in);

	return (EXIT_SUCCESS);
}
