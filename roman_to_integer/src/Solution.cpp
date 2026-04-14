/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:19:56 by abelov            #+#    #+#             */
/*   Updated: 2026/03/25 13:19:56 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

int  Solution::romanToInt(std::string s)
{
	const std::array<int, UCHAR_MAX + 1> lookup_table = [] {
		std::array<int, UCHAR_MAX + 1> tbl{};
		tbl['I'] = 1;
		tbl['V'] = 5;
		tbl['X'] = 10;
		tbl['L'] = 50;
		tbl['C'] = 100;
		tbl['D'] = 500;
		tbl['M'] = 1000;
		return tbl;
	}();

	int result = 0;

	for (size_t i = 0; i < s.size(); ++i) {
		int curr = lookup_table[(unsigned char)s[i]];
		int next = (i + 1 < s.size()) ? lookup_table[(unsigned char)s[i + 1]] : 0;

		/// result += (curr < next) ? -curr : curr;
		int mask = -(static_cast<int>(curr < next));   // 0 or -1
		result += (curr ^ mask) - mask;
	}

	return result;
}
