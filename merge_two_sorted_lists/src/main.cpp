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

typedef struct s_input
{
	std::vector<int> nums1;
	std::vector<int> nums2;
	std::vector<int> expected;
}	Input;

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

int ft_do_test(Input *input)
{
	std::vector<int> *result;
	Solution::ListNode *resultList;
	Solution::ListNode *list1 = toList(input->nums1);
	Solution::ListNode *list2 = toList(input->nums2);
	Solution sol;
	int check_val;

	resultList = sol.mergeTwoLists(list1, list2);
	result = toArray(resultList);
	check_val = input->expected.size() == result->size();
	if (!check_val)
	{
		std::cout << "got array of size [\"" << result->size()
				  << "\"] whilst \"" << input->expected.size()
				  << "\" was to be expected" << std::endl;
	}
	else if ((check_val = (input->expected == *result)) != 1)
	{
		check(check_val);
		std::cout << "got " << *result << " whilst " << input->expected
				  << " was to be expected" << std::endl;
	}
	else
		check(check_val);
	delete result;
	listFree(resultList);
	return (0);
}

int main()
{

	Input inputs[] = {
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
	};

	for (auto in: inputs)
		ft_do_test(&in);

	return (EXIT_SUCCESS);
}
