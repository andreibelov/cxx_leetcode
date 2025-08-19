#include "Solution.hpp"
#include "leetcode_150.hpp"

using Input = struct s_input
{
	std::vector<int> nums;
	int val;
	int expected;
};

int ft_do_test(Input *input)
{
	std::vector<int> &result = input->nums;
	int check_val;

	Solution sol;
	sol.solve(input->nums, input->val);
	check_val = input->expected.size() == input->nums.size();
	if (!check_val)
	{
		std::cout << "got array of size [\"" << result.size()
				  << "\"] whilst [\"" << input->expected.size()
				  << "\"] was to be expected" << std::endl;
	}
	else if ((check_val = (input->expected == input->nums)) != 1)
	{
		check(check_val);
		std::cout << "got " << result << " whilst " << input->expected
				  << " was to be expected" << std::endl;
	}
	else
		check(check_val);
	return (0);
}

int main()
{

	auto inputs = std::to_array<Input>({
		{
			.nums = {3, 2, 2, 3},
			.val = 3,
			.expected = {2, 2}
		},
		{
			.nums = {0, 1, 2, 2, 3, 0, 4, 2},
			.val = 2,
			.expected = {0, 1, 4, 0, 3}
		},
	});

	for (Input in: inputs)
		ft_do_test(&in);

	return (EXIT_SUCCESS);
}
