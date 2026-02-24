/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:52:11 by abelov            #+#    #+#             */
/*   Updated: 2025/10/16 14:52:11 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::string	in;
	std::string	expected;
};

int ft_do_test(Input &input)
{
	bool check_val = false;

	Solution sol;
	std::string result = sol.reverseWords(input.in);
	check_val = input.expected.size() == result.size();
	if (!check_val)
	{
		std::cout << "Size mismatch: got string of size [\"" << result.size()
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
			.in = "the sky is blue",
			.expected = "blue is sky the"
		},
		{
			.in = "  hello world  ",
			.expected = "world hello"
		},
		{
			.in = "a good   example",
			.expected = "example good a"
		},
	});

	for (Input& test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
