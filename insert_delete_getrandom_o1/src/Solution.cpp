/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 23:26:33 by abelov            #+#    #+#             */
/*   Updated: 2026/03/23 23:26:33 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

int Solution::solve(std::vector<int>& nums, int val)
{
	int acc = val;
	for (int num: nums)
		acc += num;
	return acc;
}
