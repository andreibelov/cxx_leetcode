/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:49:13 by abelov            #+#    #+#             */
/*   Updated: 2025/02/28 14:49:14 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<int> nums1;
	std::vector<int> nums2;
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
	std::vector<int> stackVec = {};

	while (head)
	{
		stackVec.push_back(head->val);
		head = head->next;
	}
	return (new std::vector<int>(stackVec));
}

void listFree(Solution::ListNode *head)
{
	Solution::ListNode* next;
	while (head)
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
	Solution::ListNode *list1 = toList(input.nums1);
	Solution::ListNode *list2 = toList(input.nums2);
	Solution sol;
	bool check_val = false;

	resultList = sol.mergeTwoLists(list1, list2);
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
			.nums1 = {1,2,4},
			.nums2 = {1,3,4},
			.expected = {1,1,2,3,4,4}
		},
		{
			.nums1 = {},
			.nums2 = {},
			.expected = {}
		},
		{
			.nums1 = {},
			.nums2 = {0},
			.expected = {0}
		},
	});

	for (Input test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
