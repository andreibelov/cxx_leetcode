/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 23:43:56 by abelov            #+#    #+#             */
/*   Updated: 2026/05/07 23:43:56 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

/**
 * 131. Palindrome Partitioning
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 *
 * Constraints:
 * 	1 <= s.length <= 16
 * 	s contains only lowercase English letters.
 *
 * @param s
 * @return
 */
std::vector<std::vector<std::string>> Solution::partition(std::string s){
	int n = static_cast<int>(s.size());
	std::vector<std::vector<std::string>> partitions;
	std::vector<std::vector<bool>> isPalindrome(n, std::vector<bool>(n, true));

	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j)
			isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
	}

	std::vector<std::string> currentPart;

	struct Frame {
		int startIndex;
		int nextEndIndex;
		bool ownsCurrentPart;
	};

	std::vector<Frame> stack;
	stack.push_back({.startIndex=0, .nextEndIndex=0, .ownsCurrentPart=false});

	while (!stack.empty()) {
		Frame &frame = stack.back();

		if (frame.startIndex == n) {
			bool ownsCurrentPart = frame.ownsCurrentPart;
			partitions.push_back(currentPart);
			stack.pop_back();
			if (ownsCurrentPart)
				currentPart.pop_back();
			continue;
		}

		if (frame.nextEndIndex >= n) {
			bool ownsCurrentPart = frame.ownsCurrentPart;
			stack.pop_back();
			if (ownsCurrentPart)
				currentPart.pop_back();
			continue;
		}

		int endIndex = frame.nextEndIndex++;
		if (isPalindrome[frame.startIndex][endIndex]) {
			currentPart.push_back(s.substr(frame.startIndex, endIndex - frame.startIndex + 1));
			stack.push_back({.startIndex=endIndex + 1, .nextEndIndex=endIndex + 1, .ownsCurrentPart=true});
		}
	}

	return partitions;
}
