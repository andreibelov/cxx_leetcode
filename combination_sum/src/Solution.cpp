/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:01:14 by abelov            #+#    #+#             */
/*   Updated: 2025/09/19 15:01:14 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include "Solution.hpp"

/**
 * 39. Combination Sum
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates
 * where the chosen numbers sum to target.
 *
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 * @param candidates
 * @param target
 * @return
 */
std::vector<std::vector<int>> Solution::combinationSum(std::vector<int>& candidates, int target)
{
	std::vector<std::vector<int>> out;
	enum class e_state : std::uint8_t { LEFT = 0, RIGHT, DONE };
	using enum e_state;
	struct Frame {std::vector<int> denominators; int target; std::vector<int> so_far; e_state state;};

	std::sort(candidates.begin(), candidates.end());
	auto last = std::unique(candidates.begin(), candidates.end());
	candidates.erase(last, candidates.end());
	std::vector<Frame> st;
	st.reserve(2UL * target);

	st.push_back(Frame{
		.denominators = candidates,
		.target = target,
		.so_far = std::vector<int>(),
		.state = LEFT
	});

	while (!st.empty()) {
		Frame fr = st.back();
		st.pop_back();

		if (fr.target == 0) {
			out.push_back(fr.so_far);
			continue;
		}
		if (fr.target < 0) {
			continue;
		}

		switch (fr.state)
		{
			case e_state::LEFT: {
				Frame copy = fr;
				copy.state = RIGHT;
				st.push_back(copy);

				if (!fr.denominators.empty() && (fr.target - fr.denominators.back()) >= 0) {
					copy.target = fr.target - fr.denominators.back();
					copy.so_far.emplace_back(fr.denominators.back());
					copy.state = LEFT;
					st.push_back(copy);
				}
				break ;
			}
			case e_state::RIGHT: {
				Frame copy = fr;
				copy.state = DONE;
				st.push_back(copy);
				if (!copy.denominators.empty()) {
					copy.denominators.pop_back();
					copy.state = LEFT;
					st.push_back(copy);
				}
				break ;
			}
			case e_state::DONE:
				break;
		}

	}

	return out;
}
