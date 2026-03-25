/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 23:26:33 by abelov            #+#    #+#             */
/*   Updated: 2026/03/23 23:26:33 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RandomizedSet.hpp"
#include "leetcode_150.hpp"
#include <array>
#include <sstream>
#include <variant>

enum class Operation : std::uint8_t
{
	op_create = 0,
	op_insert,
	op_remove,
	op_get_random
};

using enum Operation;

using Input = struct s_input
{
	std::vector<Operation> ops;
	std::vector<std::array<int, 1>> args;
	std::vector<std::variant<std::monostate, bool, std::vector<int>>> expected;
};

using result_t = std::variant<std::monostate, bool, int>;

const char *op_name(Operation op)
{
	switch (op)
	{
		case op_create: return "RandomizedSet";
		case op_insert: return "insert";
		case op_remove: return "remove";
		case op_get_random: return "getRandom";
	}
	return "unknown";
}

bool is_expected(
	const result_t &result,
	const std::variant<std::monostate, bool, std::vector<int>> &expected,
	std::string &error)
{
	if (std::holds_alternative<std::monostate>(expected))
	{
		if (!std::holds_alternative<std::monostate>(result))
		{
			error = "expected null-like result";
			return false;
		}
		return true;
	}
	if (const bool *expected_bool = std::get_if<bool>(&expected))
	{
		const bool *result_bool = std::get_if<bool>(&result);
		if (!result_bool)
		{
			error = "expected bool result";
			return false;
		}
		if (*result_bool != *expected_bool)
		{
			error = "expected " + std::string(*expected_bool ? "true" : "false")
					+ " but got " + (*result_bool ? "true" : "false");
			return false;
		}
		return true;
	}

	const int *random_val = std::get_if<int>(&result);
	const std::vector<int> *allowed = std::get_if<std::vector<int>>(&expected);
	if ((random_val == nullptr) || (allowed == nullptr))
	{
		error = "expected random integer result";
		return false;
	}
	if (std::find(allowed->begin(), allowed->end(), *random_val) == allowed->end())
	{
		std::ostringstream oss;
		oss << *allowed;
		error = "expected one of " + oss.str() + " but got " + std::to_string(*random_val);
		return false;
	}
	return true;
}

int ft_do_test(Input &input)
{
	RandomizedSet randomized_set;
	bool		  check_val = true;

	for (std::size_t i = 0; i < input.ops.size(); ++i)
	{
		Operation op = input.ops[i];
		result_t result = std::monostate{};

		switch (op)
		{
			case op_create:
				randomized_set = RandomizedSet{};
				break;
			case op_insert:
				result = randomized_set.insert(input.args[i][0]);
				break;
			case op_remove:
				result = randomized_set.remove(input.args[i][0]);
				break;
			case op_get_random:
				result = randomized_set.getRandom();
				break;
			default:
				std::cout << "Unknown operation at step " << i << std::endl;
				check_val = false;
				break;
		}

		std::string reason;
		if (!is_expected(result, input.expected[i], reason))
		{
			std::cout << "Mismatch at step " << i << " command '" << op_name(op)
					  << "': " << reason << std::endl;
			check_val = false;
			break;
		}
	}
	check(check_val);
	return (0);
}

int main()
{
	auto	inputs = std::to_array<Input>(
	{
		{
			.ops = {op_create, op_insert, op_remove, op_insert, op_get_random, op_remove, op_insert,
					op_get_random},
			.args = {{0}, {1}, {2}, {2}, {0}, {1}, {2}, {0}},
			.expected = {std::monostate{}, true, false, true, std::vector<int>{2}, true, false,
						 std::vector<int>{2}}
		},
		{
			.ops = {op_create, op_insert, op_insert, op_insert, op_remove, op_get_random, op_remove,
					op_get_random},
			.args = {{0}, {10}, {20}, {30}, {20}, {0}, {10}, {0}},
			.expected = {std::monostate{}, true, true, true, true, std::vector<int>{10, 30}, true,
						 std::vector<int>{30}}
		},
	});

	for (Input& test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
