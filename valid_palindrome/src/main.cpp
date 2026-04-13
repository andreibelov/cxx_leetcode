/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:59:56 by abelov            #+#    #+#             */
/*   Updated: 2026/04/13 13:59:56 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"


#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input {
	std::string input;
	bool		expected;
};

int ft_do_test(Input &input)
{
	bool check_val = false;
	bool result	   = false;

	Solution sol;
	result	  = sol.isPalindrome(input.input);
	check_val = (input.expected == result);
	if (!check_val) {
		std::cout << "got [\"" << (result ? "true" : "false" )
				  << "\"] whilst [\"" << (input.expected ? "true" : "false" )
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
				.input = "A man, a plan, a canal: Panama",
				.expected = true
			},
			{
				.input = "race a car",
				.expected = false
			},
			{
				.input = "",
				.expected = true
			},
			{
				.input = "a",
				.expected = true
			},
		});

	for (Input &test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}