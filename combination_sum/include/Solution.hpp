/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:01:14 by abelov            #+#    #+#             */
/*   Updated: 2025/09/19 15:01:14 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

class Solution {
public:
	/**
	 *
	 * @param candidates
	 * @param target
	 * @return
	 */
	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);
};

#endif //SOLUTION_HPP
