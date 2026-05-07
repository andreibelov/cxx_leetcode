/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:53:45 by abelov            #+#    #+#             */
/*   Updated: 2026/05/07 16:53:45 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<int>	nums;
	int 				pos;
	int					expected;
};

Solution::ListNode *toList(std::vector<int> &arr, int pos)
{
	Solution::ListNode dummy(0);
	Solution::ListNode *head = &dummy;
	Solution::ListNode *loop = nullptr;

	int curr_pos = 0;
	for (int nbr: arr)
	{
		head->next = new Solution::ListNode(nbr);
		head = head->next;
		if (curr_pos++ == pos)
			loop = head;
	}
	if (pos != -1)
		head->next = loop;
	return (dummy.next);
}

std::vector<int> *toArray(Solution::ListNode *head)
{
	std::vector<int> stackVec = {};

	while (head != nullptr)
	{
		stackVec.push_back(head->val);
		head = head->next;
	}
	return (new std::vector<int>(stackVec));
}

void listFree(Solution::ListNode *head, int pos)
{
	Solution::ListNode*	next = nullptr;
	Solution::ListNode*	loop = nullptr;

	int curr_pos = 0;
	while (head != nullptr && head != loop)
	{
		next = head->next;
		if (curr_pos++ == pos)
			loop = head;
		delete head;
		if (next == loop)
			break;
		head = next;
	}
}

int getIndex(Solution::ListNode *head, Solution::ListNode *node, int pos)
{
	Solution::ListNode*	next = nullptr;
	Solution::ListNode*	loop = nullptr;

	int curr_pos = 0;
	while (head != nullptr && head != loop)
	{
		next = head->next;
		if (node == head)
			return curr_pos;
		if (curr_pos++ == pos)
			loop = head;
		if (next == loop)
			break;
		head = next;
	}
	return (-1);
}

int ft_do_test(Input &input)
{
	bool				check_val = false;
	int					result = -1;
	Solution::ListNode*	head = toList(input.nums, input.pos);

	Solution sol;
	result = getIndex(head, sol.detectCycle(head), input.pos);
	check_val = (input.expected == result);
	if (!check_val)
	{
		std::cout << "got [\"" << result
				  << "\"] whilst [\"" << input.expected
				  << "\"] was to be expected" << std::endl;
	}
	check(check_val);
	listFree(head, input.pos);
	return (0);
}

int main()
{
	auto inputs = std::to_array<Input>(
		{
			{
				.nums = {3,2,0,-4},
				.pos = 1,
				.expected = 1
			},
			{
				.nums = {1, 2},
				.pos = 0,
				.expected = 0
			},
			{
				.nums = {1},
				.pos = -1,
				.expected = -1
			},
		}
	);

	for (Input test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
