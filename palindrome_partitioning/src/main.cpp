/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 23:43:55 by abelov            #+#    #+#             */
/*   Updated: 2026/05/07 23:43:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::string								s;
	std::vector<std::vector<std::string>>	expected;
};

int ft_do_test(Input &input)
{
	std::vector<std::vector<std::string>>	result;
	bool check_val = false;

	Solution sol;
	result = sol.partition(input.s);
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
			.s = "aab",
			.expected = {{"a","a","b"},{"aa","b"}}
		},
		{
			.s = "a",
			.expected = {{"a"}}
		},
		{
			.s = "aaab",
			.expected = {{"a","a","a","b"},{"a","aa","b"}, {"aa","a","b"}, {"aaa","b"}}
		},
		{
			.s = "abcaa",
			.expected = {{"a","b","c","a","a"},{"a","b","c","aa"}}
		},
		{
			.s = "abbab",
			.expected = {{"a","b","b","a","b"},{"a","b","bab"},{"a","bb","a","b"},{"abba","b"}}
		},
		{
			.s = "abaca",
			.expected = {{"a","b","a","c","a"},{"a","b","aca"},{"aba","c","a"}}
		},
		{
			.s = "aaa",
			.expected = {{"a","a","a"},{"a","aa"},{"aa","a"},{"aaa"}}
		},
	});

	for (Input& test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
