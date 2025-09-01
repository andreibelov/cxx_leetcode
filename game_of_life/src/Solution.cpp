/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 01:22:08 by abelov            #+#    #+#             */
/*   Updated: 2025/08/26 01:22:08 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 289. Game of Life
 *
 * Given the current state of the board,
 * update the board to reflect its next state.
 *
 * @param board
 * @return you do not need to return anything.
 */
void Solution::gameOfLife(std::vector<std::vector<int>>& board) {

	const int HEIGHT = (int)board.size();
	if (HEIGHT == 0) return;
	const int WIDTH = (int)board[0].size();
	if (WIDTH == 0) return;

	std::vector<int> cnt_curr(WIDTH, 0);
	std::vector<int> cnt_next(WIDTH, 0);

	for (int y = 0; y < HEIGHT; y++) {

		std::vector<int> &row_curr = board[y];

		for (int x = 0; x < WIDTH; x++) {
			int &curr = row_curr[x];
			if (x + 1 < WIDTH) {
				cnt_curr[x]     += row_curr[x + 1];
				cnt_curr[x + 1] += curr;
			}
			if (y + 1 < HEIGHT) {
				std::vector<int> &row_next = board[y + 1];
				cnt_curr[x] += row_next[x];
				cnt_next[x] += curr;
				if (x + 1 < WIDTH) {
					cnt_curr[x]     += row_next[x + 1];
					cnt_next[x + 1] += curr;
				}
				if (x - 1 >= 0) {
					cnt_curr[x]     += row_next[x - 1];
					cnt_next[x - 1] += curr;
				}
			}
			int alive_neighbours = cnt_curr[x];
			curr = (int) ((alive_neighbours == 3) || ((curr == 1) && (alive_neighbours == 2)));
		}
		std::swap(cnt_curr, cnt_next);
		std::fill(cnt_next.begin(), cnt_next.end(), 0);
	}
}
