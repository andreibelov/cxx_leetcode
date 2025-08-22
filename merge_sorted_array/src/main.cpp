/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:40:09 by abelov            #+#    #+#             */
/*   Updated: 2025/02/27 23:40:09 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<int> nums1;
	int m;
	std::vector<int> nums2;
	int n;
	std::vector<int> expected;
};

int ft_do_test(Input &input)
{
	std::vector<int> &result = input.nums1;
	bool check_val = false;

	Solution sol;
	sol.merge(input.nums1, input.m, input.nums2, input.n);
	check_val = input.expected.size() == input.nums1.size();
	if (!check_val)
	{
		std::cout << "got array of size [\"" << result.size()
				  << "\"] whilst [\"" << input.expected.size()
				  << "\"] was to be expected" << std::endl;
	}
	else
	{
		check_val = (input.expected == input.nums1);
		if (!check_val)
		{
			std::cout << "got " << result
					  << " whilst " << input.expected
					  << " was to be expected" << std::endl;
		}
	}
	check(check_val);
	return (0);
}

int main()
{
	auto inputs = std::to_array<Input>(
	{
		{
			.nums1 = {0}, .m = 0,
			.nums2 = {1}, .n = 1,
			.expected = {1}
		},
		{
			.nums1 = {1}, .m = 1,
			.nums2 = {}, .n = 0,
			.expected = {1}
		},
		{
			.nums1 = {1, 2, 3, 0, 0, 0}, .m = 3,
			.nums2 = {2, 5, 6}, .n = 3,
			.expected = {1, 2, 2, 3, 5, 6}
		},
	});

	for (Input test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
