/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:58:18 by abelov            #+#    #+#             */
/*   Updated: 2025/03/03 22:58:19 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_150.hpp"
#include <array>
#include <optional>
#include <vector>
#include "LRUCache.hpp"



using Input = struct s_input
{
	std::vector<Operation> ops;
	std::vector<std::array<int, 2>> args;
	std::vector<std::optional<int>> expected;
};

const char *op_name(Operation op)
{
	switch (op)
	{
		case op_create: return "LRUCache";
		case op_put: return "put";
		case op_get: return "get";
	}
	return "unknown";
}

int ft_do_test(Input &input)
{
	bool check_val = input.ops.size() == input.expected.size() && input.ops.size() == input.args.size();
	LRUCache *cache = nullptr;

	if (!check_val)
	{
		std::cout << "Size mismatch: got ops/args/expected sizes ["
				  << input.ops.size() << "/" << input.args.size() << "/"
				  << input.expected.size() << "] whilst all should match" << std::endl;
		check(check_val);
		return (0);
	}

	for (std::size_t i = 0; i < input.ops.size(); ++i)
	{
		Operation op = input.ops[i];
		std::optional<int> result = std::nullopt;

		switch (op)
		{
			case op_create:
				delete cache;
				cache = new LRUCache(input.args[i][0]);
				break;
			case op_put:
				if (cache == nullptr)
				{
					std::cout << "Command 'put' used before 'LRUCache' at step " << i << std::endl;
					check_val = false;
					break;
				}
				cache->put(input.args[i][0], input.args[i][1]);
				break;
			case op_get:
				if (cache == nullptr)
				{
					std::cout << "Command 'get' used before 'LRUCache' at step " << i << std::endl;
					check_val = false;
					break;
				}
				result = cache->get(input.args[i][0]);
				break;
			default:
				std::cout << "Unknown operation at step " << i << std::endl;
				check_val = false;
				break;
		}
		if (!check_val)
			break;

		if (result.has_value() != input.expected[i].has_value())
		{
			std::cout << "Mismatch at step " << i << " command '" << op_name(op)
					  << "': expected "
					  << (input.expected[i].has_value() ? "value" : "null")
					  << " but got " << (result.has_value() ? "value" : "null")
					  << std::endl;
			check_val = false;
			break;
		}
		if (result.has_value() && result.value() != input.expected[i].value())
		{
			std::cout << "Mismatch at step " << i << " command '" << op_name(op)
					  << "': expected " << input.expected[i].value()
					  << " but got " << result.value() << std::endl;
			check_val = false;
			break;
		}
	}
	delete cache;
	check(check_val);
	return (0);
}

int main()
{
	auto inputs = std::to_array<Input>(
	{
		{
			.ops = {op_create, op_put, op_put, op_get, op_put, op_get, op_put, op_get, op_get, op_get},
			.args = {{2, 0}, {1, 1}, {2, 2}, {1, 0}, {3, 3}, {2, 0}, {4, 4}, {1, 0}, {3, 0}, {4, 0}},
			.expected = {std::nullopt, std::nullopt, std::nullopt, 1, std::nullopt, -1, std::nullopt,
						 -1, 3, 4}
		},
		{
			.ops = {op_create, op_get, op_put, op_get},
			.args = {{1, 0}, {7, 0}, {7, 70}, {7, 0}},
			.expected = {std::nullopt, -1, std::nullopt, 70}
		},
	});

	for (Input &test: inputs)
		ft_do_test(test);

	return (EXIT_SUCCESS);
}
