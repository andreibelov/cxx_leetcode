/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 01:11:08 by abelov            #+#    #+#             */
/*   Updated: 2026/02/25 01:11:08 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input {
	std::string haystack;
	std::string needle;
	int			expected;
};

int ft_do_test(Input &input)
{
	bool check_val = false;
	int	 result	   = 0;

	Solution sol;
	result	  = sol.strStr(input.haystack, input.needle);
	check_val = (input.expected == result);
	if (!check_val) {
		std::cout << "got [\"" << result << "\"] whilst [\"" << input.expected
				  << "\"] was to be expected" << std::endl;
	}
	check(check_val);
	return (0);
}

int main()
{
	auto inputs = std::to_array<Input>(
		{
			{
				.haystack = "sadbutsad",
				.needle = "sad",
				.expected = 0
			},
			{
				.haystack = "leetcode",
				.needle = "leeto",
				.expected = -1
			},
		});

	for (Input &test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
