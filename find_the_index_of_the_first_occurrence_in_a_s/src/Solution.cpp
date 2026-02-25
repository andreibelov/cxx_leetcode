/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 01:11:08 by abelov            #+#    #+#             */
/*   Updated: 2026/02/25 01:11:08 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include "Solution.hpp"

char *ft_strstr(const char *str, const char *to_find) {
    const char *save = to_find;
    const char *s;

    if (!strlen(to_find))
        return const_cast<char *>(str);
    while (*str) {
        s = str;
        to_find = save;
        while (*to_find++ == *s++)
            if (!*to_find)
                return const_cast<char *>(str);
        str++;
    }
    return (NULL);
}

/**
 * 28. Find the Index of the First Occurrence in a String
 *
 * Given two strings needle and haystack
 * @param haystack
 * @param needle
 * @return the index of the first occurrence
 * of needle in haystack, or -1 if needle is not part of haystack.
 */
int Solution::strStr(std::string haystack, std::string needle) {
    char *substr = ft_strstr(haystack.c_str(), needle.c_str());

    if (substr == NULL)
        return (-1);

    ptrdiff_t ans = substr - haystack.c_str();
    return (int) ans;
}
