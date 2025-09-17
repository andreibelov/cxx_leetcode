/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 01:57:45 by abelov            #+#    #+#             */
/*   Updated: 2025/09/17 01:57:45 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 104. Maximum Depth of Binary Tree
 *
 * @param root
 * @return
 */
int Solution::maxDepth(TreeNode *root)
{
	typedef std::pair<TreeNode *, int> stack_elem_t;
	if (root == nullptr) return (0);
	int	depth = 0;
	std::vector<stack_elem_t>	stack;
	stack_elem_t elem = {root , depth + 1}, left, right;
	stack.push_back(elem);
	while (!stack.empty())
	{
		elem = stack.back();
		stack.pop_back();
		depth = std::max(depth, elem.second);

		if (elem.first->right != nullptr)
		{
			right = {elem.first->right , elem.second + 1};
			stack.push_back(right);
		}
		if (elem.first->left != nullptr)
		{
			left = {elem.first->left , elem.second + 1};
			stack.push_back(left);
		}
	}
	return (depth);
}

void free_tree(TreeNode *root)
{
	if (root == nullptr) return;

	TreeNode *node = nullptr;
	std::vector<TreeNode *> stack;

	stack.push_back(root);

	while (!stack.empty())
	{
		node = stack.back();
		stack.pop_back();
		if (node->right != nullptr)
			stack.push_back(node->right);
		if (node->left != nullptr)
			stack.push_back(node->left);
		delete node;
	}
}

TreeNode *deserialize_level_order(std::vector<std::optional<int>> &nums)
{
	TreeNode	*root = nullptr;
	std::queue<TreeNode *> q;

	std::reverse(nums.begin(), nums.end());

	if (!nums.empty() && nums.back().has_value())
	{
		root = new TreeNode(nums.back().value());
		nums.pop_back();
		q.push(root);
		while (!nums.empty())
		{
			TreeNode *node = q.front();
			q.pop();

			{ // handle left child
				std::optional<int> num = nums.back();
				nums.pop_back();

				if (num.has_value())
				{
					auto *new_node = new TreeNode(num.value());
					node->left = new_node;
					q.push(new_node);
				}
			}

			if (!nums.empty()) { // handle right child
				std::optional<int> num = nums.back();
				nums.pop_back();

				if (num.has_value())
				{
					auto *new_node = new TreeNode(num.value());
					node->right = new_node;
					q.push(new_node);
				}
			}
		}
	}
	return root;
}
