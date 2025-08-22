/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:45:37 by abelov            #+#    #+#             */
/*   Updated: 2025/08/17 00:45:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

class Solution {
public:
	int removeDuplicates(std::vector<int>& nums);

	int removeDuplicatesFaster(std::vector<int> &nums);

	int removeDuplicatesFast(std::vector<int> &nums);
};
