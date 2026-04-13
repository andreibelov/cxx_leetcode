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
	int (*toLower)(unsigned char) = [](unsigned char c) { return std::tolower(c); };
	std::transform(str.begin(), str.end(), str.begin(), toLower);

	bool (*isNonAlphanumeric)(unsigned char) = [](unsigned char c) { return !std::isalnum(c); };
	auto iterator = std::remove_if(str.begin(), str.end(), isNonAlphanumeric);
	str.erase(iterator, str.end());

	if (str.empty() || str.size() == 1)
		return true;

	size_t start = 0;
	size_t end = str.size() - 1;

	while(start <= end) {
		if ((unsigned char)str[start++] != (unsigned char)str[end--])
			return false;
	}

	return true;
}
