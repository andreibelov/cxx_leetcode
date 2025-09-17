/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 01:57:45 by abelov            #+#    #+#             */
/*   Updated: 2025/09/17 01:57:45 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<std::optional<int>>	nums;
	int								expected;
};

int ft_do_test(Input &input)
{
	int result = 0;
	bool check_val = false;

	TreeNode	*root = deserialize_level_order(input.nums);

	Solution sol;
	result = sol.maxDepth(root);
	check_val = (input.expected == result);
	if (!check_val)
	{
		std::cout << "Value mismatch: got [\"" << result
				  << "\"] whilst [\"" << input.expected
				  << "\"] was to be expected" << std::endl;
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
			.nums = {3,9,20,std::nullopt,std::nullopt,15,7},
			.expected = 3
		},
		{
			.nums = {1,std::nullopt,2},
			.expected = 2
		},
		{
			.nums = {1,2,3,4,std::nullopt,std::nullopt,5},
			.expected = 3
		},
	});

	for (Input& test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
