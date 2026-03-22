/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:48:08 by abelov            #+#    #+#             */
/*   Updated: 2026/03/22 22:48:08 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 274. H-Index
 *
 * Given an array of integers citations where citations[i] is the number
 * of citations a researcher received for their ith paper,
 * return the researcher's h-index.
 */
int Solution::hIndex(std::vector<int> &citations)
{
	std::sort(citations.rbegin(), citations.rend());
	for (int h = (int)citations.size(); h > 0; --h)
		if (citations[h - 1] >= h) return h;
	return 0;
}
