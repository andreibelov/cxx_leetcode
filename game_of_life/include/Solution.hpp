/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 01:22:08 by abelov            #+#    #+#             */
/*   Updated: 2025/08/26 01:22:08 by abelov           ###   ########.fr       */
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
	 * 289. Game of Life
	 *
	 * Given the current state of the board,
	 * update the board to reflect its next state.
	 *
	 * @param board
	 * 	Constraints:
	 * 		m == board.length
	 * 		n == board[i].length
	 * 		1 <= m, n <= 25
	 * 		board[i][j] is 0 or 1.
	 * @return you do not need to return anything.
	 */
	void gameOfLife(std::vector<std::vector<int>>& board);
};

#endif //SOLUTION_HPP
