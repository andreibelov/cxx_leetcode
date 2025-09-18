/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:22:56 by abelov            #+#    #+#             */
/*   Updated: 2025/09/17 18:22:56 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	int							val;
	std::vector<std::string>	expected;
};

int ft_do_test(Input &input)
{
	std::vector<std::string> result;
	bool check_val = false;

	Solution sol;
	result = sol.generateParenthesis(input.val);
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
	return (0);
}

int main()
{
	auto	inputs = std::to_array<Input>(
	{
		{
			.val = 3,
			.expected = {"((()))","(()())","(())()","()(())","()()()"}
		},
	});

	for (Input& test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
