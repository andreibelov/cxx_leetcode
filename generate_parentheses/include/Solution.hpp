/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:22:56 by abelov            #+#    #+#             */
/*   Updated: 2025/09/17 18:22:56 by abelov           ###   ########.fr       */
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
	std::vector<std::string> generateParenthesis(int n);
	std::vector<std::string> generateParenthesis2(int n);
	std::vector<std::string> generateParenthesis3(int n);
};

#endif //SOLUTION_HPP
