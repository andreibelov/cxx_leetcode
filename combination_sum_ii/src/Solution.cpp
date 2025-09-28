/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 03:11:01 by abelov            #+#    #+#             */
/*   Updated: 2025/09/22 03:11:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <cstdint>
#include "Solution.hpp"

/**
 * 40. Combination Sum II
 * Given a collection of candidate numbers (candidates) and a target number,
 * find all unique combinations in candidates where the candidate numbers
 * sum to target.
 *
 * @param candidates
 * @param target
 * @return all unique combinations in candidates where the candidate numbers
 * sum to target
 */
std::vector<std::vector<int>> Solution::combinationSum2(std::vector<int>& candidates, int target)
{
	std::sort(candidates.begin(), candidates.end());

	enum class e_state : std::uint8_t { PRE_CHILD = 0, POST_CHILD };
	using enum e_state;
	struct Frame { size_t start; size_t idx; int rem; e_state state; };

	std::vector<std::vector<int>> out;
	std::vector<int> path;
	std::vector<Frame> st;

	const size_t n = candidates.size();
	if (n == 0) return out;

	st.push_back(Frame{.start=0, .idx=0, .rem=target, .state=PRE_CHILD});

	while (!st.empty()) {
		Frame fr = st.back();
		st.pop_back();

		if (fr.rem == 0) {
			out.push_back(path);
			continue;
		}
		if (fr.start >= n || candidates[fr.start] > fr.rem) {
			continue;
		}

		switch (fr.state) {
			case PRE_CHILD: {
				bool found = false;

				while (fr.idx < n) {
					if (candidates[fr.idx] > fr.rem)
						break;

					if (fr.idx > fr.start && candidates[fr.idx] == candidates[fr.idx - 1]) {
						fr.idx++;
						continue;
					}
					found = true;
					break;
				}

				if (found) {
					fr.state = POST_CHILD;
					st.push_back(fr);

					path.push_back(candidates[fr.idx]);

					st.push_back(Frame{
						.start = fr.idx + 1,
						.idx = fr.idx + 1,
						.rem = fr.rem - candidates[fr.idx],
						.state = PRE_CHILD,
					});
				}
				break;
			}

			case POST_CHILD: {
				path.pop_back();
				fr.idx++;
				fr.state = PRE_CHILD;
				st.push_back(fr);
				break;
			}
		}
	}

	return out;
}

/**
 * 40. Combination Sum II
 * Given a collection of candidate numbers (candidates) and a target number,
 * find all unique combinations in candidates where the candidate numbers
 * sum to target.
 *
 * @param candidates
 * @param target
 * @return all unique combinations in candidates where the candidate numbers
 * sum to target
 */
std::vector<std::vector<int>> Solution::combinationSum2_rec(std::vector<int>& candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	std::vector<std::vector<int>> result;
	std::vector<int> curr;

	std::function<void(size_t, int)> backtrack = [&](size_t startIndex, int remainingTarget) -> void {
		if (remainingTarget == 0) {
			result.emplace_back(curr);
			return;
		}
		if (startIndex >= candidates.size() ||
			remainingTarget < candidates[startIndex])
			return;

		for (size_t currentIndex = startIndex; currentIndex < candidates.size(); ++currentIndex) {
			if (currentIndex > startIndex && candidates[currentIndex] == candidates[currentIndex - 1])
				continue;
			curr.emplace_back(candidates[currentIndex]);
			backtrack(currentIndex + 1, remainingTarget - candidates[currentIndex]);
			curr.pop_back();
		}
	};
	backtrack(0, target);
	return result;
}




