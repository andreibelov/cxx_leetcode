/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomizedSet.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 23:28:31 by abelov            #+#    #+#             */
/*   Updated: 2026/03/23 23:28:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RandomizedSet.hpp"

bool RandomizedSet::insert(int val)
{
	if (valueToIndex.contains(val))
		return false;
	valueToIndex[val] = static_cast<int>(values.size());
	values.push_back(val);
	return true;
}

bool RandomizedSet::remove(int val)
{
	if (!valueToIndex.contains(val))
		return false;

	int indexToRemove = valueToIndex[val];
	int lastValue = values.back();

	values[indexToRemove] = lastValue;
	valueToIndex[lastValue] = indexToRemove;

	values.pop_back();
	valueToIndex.erase(val);
	return true;
}

/**
 * CLang-Tidy warning that rand() has limited randomness:
 * 	@see https://stackoverflow.com/questions/59323393/
 */
int RandomizedSet::getRandom()
{
	std::size_t idx = std::rand() % values.size();
	return values[idx];
}
