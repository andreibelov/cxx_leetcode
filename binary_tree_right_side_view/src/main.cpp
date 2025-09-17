/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:03:56 by abelov            #+#    #+#             */
/*   Updated: 2025/09/17 12:03:56 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

#define null std::nullopt
using Input = struct s_input
{
	std::vector<std::optional<int>>	nums;
	std::vector<int>				expected;
};

int ft_do_test(Input &input)
{
	std::vector<int> result;
	bool check_val = false;

	TreeNode	*root = deserialize_level_order(input.nums);

	Solution sol;
	result = sol.rightSideView(root);
	check_val = input.expected.size() == result.size();
	if (!check_val)
	{
		std::cout << "Size mismatch: got array of size [\"" << result.size()
				  << "\"] whilst [\"" << input.expected.size()
				  << "\"] was to be expected" << std::endl;
	}
	else {
		check_val = (input.expected == result);
		if (!check_val)
			std::cout << "Value mismatch: got " << result
					  << " whilst " << input.expected
					  << " was to be expected"
					  << std::endl;
	}
	check(check_val);
	free_tree(root);
	return (0);
}

int main()
{
	auto	inputs = std::to_array<Input>(
		{
			{
				.nums = {1,2,3,null,5,null,4},
				.expected = {1,3,4}
			},
			{
				.nums = {1,2,3,4,null,null,null,5},
				.expected = {1,3,4,5}
			},
			{
				.nums = {1,null,3},
				.expected = {1,3}
			},
			{
				.nums = {},
				.expected = {}
			},
		});

	for (Input& test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
