/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:04:30 by abelov            #+#    #+#             */
/*   Updated: 2025/02/26 13:04:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "Solution.hpp"


/**
 * 20. Valid Parentheses
 *
 *
 * @param s
 * @return
 */
bool Solution::isValid(std::string s)
{
	std::vector<char> stack;

	for(auto c : s){
		if (c == '(' || c == '{' || c == '[')
			stack.push_back(c);
		else if (c == ')' || c == '}' || c == ']')
		{
			char opening = (char) (c - (c == ')' ? 1 : 2));
			if (!stack.empty() && opening == stack.back()) stack.pop_back();
			else
				return (false);
		}
	}
	if (!stack.empty())
		return (false);
	return (true);
}
