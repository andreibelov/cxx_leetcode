#include "Solution.hpp"

int Solution::solve(std::vector<int>& nums, int val)
{
	// TODO: implement
	int acc = val;
	for (int num: nums)
		acc += num;
	return acc;
}
