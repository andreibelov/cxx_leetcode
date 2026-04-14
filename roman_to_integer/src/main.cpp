/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:19:56 by abelov            #+#    #+#             */
/*   Updated: 2026/03/25 13:19:56 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	const std::string	str;
	int					expected;
};

int ft_do_test(Input &input)
{
	Solution sol;
	int  result = sol.romanToInt(input.str);
	bool check_val = (input.expected == result);
	if (!check_val)
	{
		std::cout << "for \"" << input.str << "\" got " << result
				  << " whilst " << input.expected
				  << " was to be expected" << std::endl;
	}
	check(check_val);
	return (0);
}

int main()
{
	auto inputs = std::to_array<Input>(
	{
		{ .str = "III",     .expected = 3    },
		{ .str = "IV",      .expected = 4    },
		{ .str = "IX",      .expected = 9    },
		{ .str = "LVIII",   .expected = 58   },
		{ .str = "XL",      .expected = 40   },
		{ .str = "XC",      .expected = 90   },
		{ .str = "CD",      .expected = 400  },
		{ .str = "CM",      .expected = 900  },
		{ .str = "MCMXCIV", .expected = 1994 },
	});

	for (Input& test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
