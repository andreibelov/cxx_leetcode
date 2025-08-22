/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:00:09 by abelov            #+#    #+#             */
/*   Updated: 2025/04/16 12:00:10 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

typedef struct s_input
{
	std::vector<int>	nums;
	int 				k;
	std::vector<int>	expected;
}	Input;

int ft_do_test(Input &input)
{
	std::vector<int> result = input.nums;
	Solution sol;
	bool check_val = false;

	sol.rotate(result, input.k);
	check_val = input.expected.size() == result.size();
	if (!check_val)
	{
		std::cout << "got array of size [\"" << result.size()
				  << "\"] whilst \"" << input.expected.size()
				  << "\" was to be expected" << std::endl;
	}
	else if ((check_val = (input.expected == result)) != 1)
	{
		check(check_val);
		std::cout << "got " << result << " whilst " << input.expected
				  << " was to be expected" << std::endl;
	}
	else
		check(check_val);
	return (0);
}

int main()
{
	auto inputs = std::to_array<Input>(
	{
		{
			.nums = {1,2,3,4,5,6,7},
			.k = 3,
			.expected = {5,6,7,1,2,3,4}
		},
		{
			.nums = {-1,-100,3,99},
			.k = 2,
			.expected = {3,99,-1,-100}
		},
	});

	for (Input test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
