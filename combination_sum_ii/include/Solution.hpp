/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 03:11:01 by abelov            #+#    #+#             */
/*   Updated: 2025/09/22 03:11:01 by abelov           ###   ########.fr       */
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
	std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);
	std::vector<std::vector<int>> combinationSum2_rec(std::vector<int>& candidates, int target);
};

#endif //SOLUTION_HPP
