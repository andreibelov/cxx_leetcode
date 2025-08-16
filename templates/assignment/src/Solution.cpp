#include "Solution.hpp"

int Solution::solve(const std::vector<int>& nums)
{
	// TODO: implement
	int acc = 0;
	for (int num: nums)
		acc += num;
	return acc;
}
