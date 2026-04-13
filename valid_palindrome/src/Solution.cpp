/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:59:56 by abelov            #+#    #+#             */
/*   Updated: 2026/04/13 13:59:56 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

bool  Solution::isPalindrome(std::string str)
{
	if (str.empty() || str.size() == 1)
		return true;

	size_t start = 0;
	size_t end = str.size() - 1;

	while(start <= end) {
		while (start < end && std::isalnum((unsigned char)str[start]) == 0) ++start;
		while (end > start && std::isalnum((unsigned char)str[end]) == 0) --end;

		if (start == end)
			break;

		int lhs = std::tolower((unsigned char) str[start++]);
		int rhs = std::tolower((unsigned char) str[end--]);
		if (lhs != rhs)
			return false;
	}

	return true;
}
