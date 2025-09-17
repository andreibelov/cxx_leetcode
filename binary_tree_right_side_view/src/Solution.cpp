/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:03:56 by abelov            #+#    #+#             */
/*   Updated: 2025/09/17 12:03:56 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue>
#include "Solution.hpp"

/**
 * 199. Binary Tree Right Side View
 *
 * @param root
 * @return
 */
std::vector<int> Solution::rightSideView(TreeNode *root)
{
	if (root == nullptr) return {};
	std::vector<int> view;
	std::queue<std::pair<TreeNode *, int>> q;
	std::pair<TreeNode *, int> el;

	int current_lvl = 0;
	el.first = root;
	el.second = 1;
	q.push(el);

	while (!q.empty())
	{
		el = q.front();
		q.pop();
		if (current_lvl < el.second)
		{
			current_lvl = el.second;
			view.push_back(el.first->val);
		}
		if (el.first->right != nullptr)
			q.emplace(el.first->right, el.second + 1);
		if (el.first->left != nullptr)
			q.emplace(el.first->left, el.second + 1);
	}
	return (view);
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
