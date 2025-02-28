/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leetcode_150.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:35:27 by abelov            #+#    #+#             */
/*   Updated: 2025/02/26 13:35:27 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef LEETCODE_150_HPP
#define LEETCODE_150_HPP

#include <iostream>
#include <iterator>

# define FT_RED   "\033[0;31m"
# define FT_GREEN "\033[0;32m"
# define FT_CYAN  "\033[36m"
# define FT_RESET "\e[0m"

void check(bool succes)
{

	std::cout
		<< (succes ? "> " FT_GREEN".OK " FT_RESET : "> " FT_RED".KO " FT_RESET)
		<< std::endl;
}

void printVector(const std::vector<int> &v)
{
	std::cout << "[";
	if (!v.empty())
	{
		std::copy(v.begin(), v.end() - 1,
				  std::ostream_iterator<int>(std::cout, ", "));
		std::cout << v.back();
	}
	std::cout << "]";
}

std::ostream &operator<<(std::ostream &os, const std::vector<int> &v)
{
	os << "[";
	if (!v.empty())
	{
		std::copy(v.begin(), v.end() - 1,
				  std::ostream_iterator<int>(os, ", "));
		os << v.back();
	}
	os << "]";
	return os;
}

#endif //LEETCODE_150_HPP
