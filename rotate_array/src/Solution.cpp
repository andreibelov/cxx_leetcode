/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:23:32 by abelov            #+#    #+#             */
/*   Updated: 2025/04/24 15:23:32 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

void Solution::rotate(std::vector<int> &nums, int k)
{
        int num_elements = nums.size();  // Get the number of elements in the vector
        k %= num_elements;               // Ensure k is within the bounds of the vector's size

        // Reverse the entire vector
        std::reverse(nums.begin(), nums.end());  // This puts the last k elements in front

        // Reverse the first k elements to restore their original order
		std::reverse(nums.begin(), nums.begin() + k);

        // Reverse the remaining elements to restore their original order
		std::reverse(nums.begin() + k, nums.end());
}
