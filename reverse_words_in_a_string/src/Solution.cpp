/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:52:11 by abelov            #+#    #+#             */
/*   Updated: 2025/10/16 14:52:11 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Solution.hpp"

/**
 * 151. Reverse Words in a String
 *
 * Given an input string str, reverse the order of the words.
 * A word is defined as a sequence of non-space characters.
 * The words in str will be separated by at least one space.
 *
 * @param in
 * @return string of the words in reverse order concatenated by a single space.
 */
std::string Solution::reverseWords(const std::string &str) {
    std::istringstream iss(str);
    std::ostringstream oss;
    std::vector<std::string> stack;

    for (std::string token; iss >> token;)
        stack.push_back(token);

    if (!stack.empty()) {
        oss << stack.back();
        stack.pop_back();
    }

    while (!stack.empty()) {
        oss << " ";
        oss << stack.back();
        stack.pop_back();
    }
    return (oss.str());
}

std::string Solution::reverseWords2(std::string s) {
    size_t n = s.size();
    std::reverse(s.begin(), s.end());
    std::ostringstream oss;

    for (size_t i = 0; i < n; ++i) {
        std::string word = "";
        while (i < n && s[i] != ' ')
            word += s[i++];
        reverse(word.begin(),word.end());
        if (!word.empty())
            oss << " " << word;
    }

    return (oss.str().substr(1));
}