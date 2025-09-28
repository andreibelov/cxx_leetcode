/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 03:11:01 by abelov            #+#    #+#             */
/*   Updated: 2025/09/22 03:11:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<int>				candidates;
	int								target;
	std::vector<std::vector<int>>	expected;
};


int ft_do_test(Input &input)
{
	std::vector<std::vector<int>> results;
	bool check_val = false;

	Solution sol;
	results = sol.combinationSum2(input.candidates, input.target);
	check_val = input.expected.size() == results.size();
	if (!check_val)
	{
		std::cout << "Size mismatch: got array of size [\"" << results.size()
				  << "\"] whilst [\"" << input.expected.size()
				  << "\"] was to be expected" << std::endl;
	}
	else {

		for (size_t j = 0; j < results.size(); ++j)
		{
			const std::vector<int>& expected = input.expected[j];
			const std::vector<int>& result = results[j];
			if (result != expected)
			{
				std::cout << "Value mismatch at index " << j
						  << ": got " << result
						  << " whilst " << expected
						  << " was to be expected"
						  << std::endl;
				check_val = false;
			}
		}
	}
	check(check_val);
	return (0);
}

int main()
{
	auto	inputs = std::to_array<Input>(
		{
			{
				.candidates = {10,1,2,7,6,1,5},
				.target = 8,
				.expected = {{1,1,6}, {1,2,5}, {1,7}, {2,6}}
			},
			{
				.candidates = {2,5,2,1,2},
				.target = 5,
				.expected = {{1,2,2}, {5}}
			},
		});

	for (Input& test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}

