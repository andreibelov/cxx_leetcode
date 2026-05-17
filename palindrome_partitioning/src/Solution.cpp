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


void backtrack(
	const std::string& s,
	size_t n,
	const std::vector<std::vector<bool>>& isPalindrome,
	std::vector<std::string>& current,
	std::vector<std::vector<std::string>>& result,
	size_t startIndex
) {
	if (startIndex != n) {

		size_t endIndex = startIndex;

		while (endIndex < n) {
			if (isPalindrome[startIndex][endIndex]) {
				const std::string &substr = s.substr(startIndex, endIndex - startIndex + 1);
				current.push_back(substr);

				backtrack(s, n, isPalindrome, current, result, endIndex + 1);

				current.pop_back();
			}

			++endIndex;
		}
	} else {
		result.push_back(current);
	}
}

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

	std::function<void(int)> backtrack = [&](int startIndex) -> void {
		if (startIndex != n) {
			int endIndex = startIndex;

			while(endIndex < n){
				if (isPalindrome[startIndex][endIndex]) {
					// If substring s[startIndex...endIndex] is palindrome
					const std::string &substr = s.substr(startIndex, endIndex - startIndex + 1);
					currentPart.push_back(substr);
					
					backtrack(endIndex + 1); // Recursively partition the remaining string

					currentPart.pop_back(); // Backtrack: remove the last added substring
				}
				++endIndex;
			}
		} else {
			partitions.push_back(currentPart);
		}
	};

	backtrack(0);

	return partitions;
}
