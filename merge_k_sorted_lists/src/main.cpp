/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:15:55 by abelov            #+#    #+#             */
/*   Updated: 2026/03/12 15:15:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector< std::vector<int> > nums;
	std::vector<int> expected;
};

Solution::ListNode *toList(std::vector<int> &arr)
{
	Solution::ListNode dummy;
	Solution::ListNode *head = &dummy;

	for (int nbr: arr)
	{
		head->next = new Solution::ListNode(nbr);
		head = head->next;
	}
	return (dummy.next);
}

std::vector<int> *toArray(Solution::ListNode *head)
{
	std::vector<int> stack = {};

	while (head != nullptr)
	{
		stack.push_back(head->val);
		head = head->next;
	}
	return (new std::vector<int>(stack));
}

void listFree(Solution::ListNode *head)
{
	Solution::ListNode* next = nullptr;
	while (head != nullptr)
	{
		next = head->next;
		delete head;
		head = next;
	}
}

int ft_do_test(Input &input)
{
	std::vector<int> *result = nullptr;
	Solution::ListNode *resultList = nullptr;

	std::vector<Solution::ListNode *> lists;

	for (std::vector<int> &it : input.nums)
		lists.push_back(toList(it));

	Solution sol;
	bool check_val = false;

	resultList = sol.mergeKLists(lists);
	result = toArray(resultList);

	check_val = input.expected.size() == result->size();
	if (!check_val)
	{
		std::cout << "got array of size [\"" << result->size()
				  << "\"] whilst \"" << input.expected.size()
				  << "\" was to be expected" << std::endl;
	}
	else {
		check_val = (input.expected == *result);
		if (!check_val)
			std::cout << "got " << *result << " whilst " << input.expected
					  << " was to be expected" << std::endl;
		check(check_val);
	}
	delete result;
	listFree(resultList);
	return (0);
}

int main()
{
	auto inputs = std::to_array<Input>(
		{
			{
				.nums = {{1,4,5},{1,3,4},{2,6}},
				.expected = {1,1,2,3,4,4,5,6}
			},
			{
				.nums = {},
				.expected = {}
			},
			{
				.nums = {{}},
				.expected = {}
			},
		});

	for (Input test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}

