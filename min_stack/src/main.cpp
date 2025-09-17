/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:16:12 by abelov            #+#    #+#             */
/*   Updated: 2025/09/16 15:16:12 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_150.hpp"
#include <unordered_map>
#include <functional>
#include <cstring>
#include "Solution.hpp"

using array_t = std::array<int, 1>;
using cnst_ref_arr_t = const array_t &;
using op_fun_t = std::function<std::optional<int> (MinStack &, cnst_ref_arr_t)>;

using Input = struct s_input
{
	std::vector<const char *>		act;
	std::vector<array_t>			args;
	std::unordered_map<std::string, op_fun_t> *ops;
	std::vector<std::optional<int>> expected;
};

int ft_do_test(Input &input)
{
	std::unordered_map<std::string, op_fun_t> &ops = *input.ops;
	std::vector<std::optional<int>> results;
	bool check_val = false;
	MinStack ms;

	size_t i = 0;
	for (const char *cmd : input.act)
	{
		if (std::strcmp(cmd, "MinStack") == 0) {
			ms = MinStack{};
			results.emplace_back(std::nullopt);
		} else {
			auto it = ops.find(cmd);
			auto an_end = ops.end();
			if (it == an_end)
				results.emplace_back(std::nullopt);
			else
			{
				cnst_ref_arr_t arg = input.args[i];
				op_fun_t &sec = it->second;
				results.push_back(sec(ms, arg));
			}
		}
		i++;
	}

	check_val = input.expected.size() == results.size();
	if (!check_val)
	{
		std::cout << "Size mismatch: got array of size [\"" << results.size()
				  << "\"] whilst [\"" << input.expected.size()
				  << "\"] was to be expected" << std::endl;
	}
	else {

		for (size_t j = 0; j < results.size(); ++j)
		{
			std::optional<int> expected = input.expected[j];
			std::optional<int> result = results[j];

			if (result.has_value() != expected.has_value()) {
				const char *result_string = nullptr;
				const char *expected_string = nullptr;
				result_string = result.has_value() ? "value" : "null";
				expected_string = expected.has_value() ? "value" : "null";

				std::cout << "Mismatch at index " << j
						  << ": got " << result_string
						  << " whilst " << expected_string
						  << " was to be expected"
						  << std::endl;
				check_val = false;
			}
			else if (result.has_value() && result.value() != expected.value())
			{
				std::cout << "Value mismatch at index " << j
						  << ": got " << result.value()
						  << " whilst " << expected.value()
						  << " was to be expected"
						  << std::endl;
				check_val = false;
			}
		}
	}
	check(check_val);
	return (0);
}

int main()
{
	std::unordered_map<std::string, op_fun_t> ops;
	ops["push"] = [](MinStack& s, cnst_ref_arr_t args) -> std::optional<int> {
		s.push(args[0]);
		return std::nullopt;
	};
	ops["pop"] = [](MinStack& s, cnst_ref_arr_t) -> std::optional<int> {
		s.pop();
		return std::nullopt;
	};
	ops["top"] = [](MinStack& s, cnst_ref_arr_t) -> std::optional<int> {
		return s.top();
	};
	ops["getMin"] = [](MinStack& s, cnst_ref_arr_t) -> std::optional<int> {
		return s.getMin();
	};

	auto	inputs = std::to_array<Input>(
	{
		{
			.act = {"MinStack","push","push","push","getMin","pop","top","getMin"},
			.args = {{}, {-2}, {0}, {-3}, {}, {}, {}, {}},
			.ops = &ops,
			.expected = {std::nullopt,std::nullopt,std::nullopt,std::nullopt,-3,std::nullopt,0,-2}
		},
	});

	for (Input& test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
