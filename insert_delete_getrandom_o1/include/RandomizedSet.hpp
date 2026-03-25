/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomizedSet.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 23:28:19 by abelov            #+#    #+#             */
/*   Updated: 2026/03/23 23:28:19 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMIZEDSET_HPP
#define RANDOMIZEDSET_HPP

#include <cstdlib>
#include <unordered_map>
#include <vector>

/**
 * 380. Insert Delete GetRandom O(1)
 *
 * Implement the RandomizedSet class:
 *
 * RandomizedSet() Initializes the RandomizedSet object.
 * bool insert(int val) Inserts an item val into the set if not present.
 * 		Returns true if the item was not present, false otherwise.
 * bool remove(int val) Removes an item val from the set if present.
 * 		Returns true if the item was present, false otherwise.
 *  int getRandom() Returns a random element from the current set of elements
 *  (it's guaranteed that at least one element exists when this method is called).
 *  Each element must have the same probability of being returned.
 *
 * implement each function such that it works in average O(1) time complexity.
 */
class RandomizedSet {
public:
	RandomizedSet() = default;

	bool insert(int val);
	bool remove(int val);
	int getRandom();

private:
	std::unordered_map<int, int> valueToIndex; // Hash map to store value -> index mapping for O(1) lookup
	std::vector<int> values;	   // Vector to store actual values and enable O(1) random access
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

#endif //RANDOMIZEDSET_HPP
