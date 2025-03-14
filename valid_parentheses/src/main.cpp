/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:58:01 by abelov            #+#    #+#             */
/*   Updated: 2025/02/26 12:58:03 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Solution.hpp"
#include "leetcode_150.hpp"

typedef struct s_input
{
	const std::string&	str;
	bool 				expected;
}	Input;

int	ft_do_test(Input* input)
{
	int	result;
	int	check_val;

	result = Solution::isValid(input->str);

	check_val = input->expected == result;
	if (!check_val)
	{
		std::cout << "for string \"" << input->str << "\" got \""
				  << (result ? "valid" : "invalid") << "\" whilst \""
				  << (input->expected ? "valid" : "invalid")
				  << "\" was to be expected" << std::endl;
	}
	check(check_val);
	return (0);
}

int main()
{
	Input	inputs[] = {
		{ .str = "()", .expected = true },
	};

	for (auto in: inputs)
		ft_do_test(&in);

	return (EXIT_SUCCESS);
}
