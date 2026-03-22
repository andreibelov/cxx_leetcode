/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:48:08 by abelov            #+#    #+#             */
/*   Updated: 2026/03/22 22:48:08 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<int> citations;
	int expected;
};

int ft_do_test(Input *input)
{
	int check_val = 0;
	int	result = 0;

	Solution sol;
	result = sol.hIndex(input->citations);
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
			.citations = {3,0,6,1,5},
			.expected = 3
		},
		{
			.citations = {1,3,1},
			.expected = 1
		},
	});

	for (Input test: inputs)
		ft_do_test(&test);

	return (EXIT_SUCCESS);
}
