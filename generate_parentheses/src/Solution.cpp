/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:22:56 by abelov            #+#    #+#             */
/*   Updated: 2025/09/17 18:22:56 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include "Solution.hpp"

/**
 * 22. Generate Parentheses
 *
 * @param n
 * @return
 */
std::vector<std::string> Solution::generateParenthesis(int n)
{
	enum e_next { TRY_L = 0, TRY_R, DONE}; // NOLINT(*-enum-size)
	struct Frame {
		int			open, close;
		size_t		len;
		enum e_next	state;
	};

	std::vector<std::string> out;
	std::vector<Frame> stack;
	std::string str_buf;

	stack.reserve(100);
	str_buf.reserve(2UL * n);

	stack.push_back(Frame{.open=0, .close=0, .len=0UL, .state = TRY_L});

	while (!stack.empty()) {
		Frame &fr = stack.back();
		str_buf.resize(fr.len);

		if (fr.len == 2UL * n) {
			out.push_back(str_buf);
			stack.pop_back();
			continue;
		}

		switch (fr.state)
		{

			case TRY_L:
				fr.state = TRY_R;
				if (fr.open < n) {
					str_buf.push_back('(');
					stack.push_back(Frame {
						.open = fr.open +1,
						.close = fr.close,
						.len = str_buf.size(),
						.state = TRY_L
					});
					continue;
				}
				[[fallthrough]];
			case TRY_R:
				fr.state = DONE;
				if (fr.close < fr.open) {
					str_buf.push_back(')');
					stack.push_back(Frame{
						.open = fr.open,
						.close = fr.close + 1,
						.len = str_buf.size(),
						.state = TRY_L
					});
					continue;
				}
				[[fallthrough]];
			case DONE:
				break;
		}
		stack.pop_back();
	}

	return out;
}


std::vector<std::string> Solution::generateParenthesis2(int n)
{
	struct Frame { std::string so_far; int open; int close; };
	std::vector<std::string> out;
	std::vector<Frame> stack; // stack.reserve(1UL + 2UL * n);

//	std::string seed; // seed.reserve(2UL * n);
//	stack.emplace_back(std::move(seed), 0, 0);
	stack.emplace_back(std::string(), 0, 0);

	while (!stack.empty()) {
		Frame fr = std::move(stack.back());
		stack.pop_back();

		if (fr.so_far.size() == (2UL * n)) {
			out.push_back(std::move(fr.so_far));
			continue;
		}
		if (fr.close < fr.open) {
			std::string copy = fr.so_far;
			copy.push_back(')');
			stack.emplace_back(std::move(copy), fr.open, fr.close + 1);
		}
		if (fr.open < n) {
			std::string copy = fr.so_far;
			copy.push_back('(');
			stack.emplace_back(std::move(copy), fr.open + 1, fr.close);
		}
	}

	return out;
}

std::vector<std::string> Solution::generateParenthesis3(int n)
{
	enum class e_next : std::uint8_t { TRY_L = 0, TRY_R, DONE };
	struct Frame { int open; int close; size_t len; e_next state;};
	using enum e_next;

	std::vector<std::string> out;
	std::vector<Frame> stack;
	std::string buf;

	buf.reserve(2UL * n);
	stack.reserve(1UL + (2UL * n));

	stack.push_back(Frame{
		.open = 0,
		.close = 0,
		.len = 0,
		.state = TRY_L
	});

	while (!stack.empty()) {
		Frame fr = stack.back();
		stack.pop_back();

		// Restore the "locals" that are implicit in recursion
		if (buf.size() != fr.len)
			buf.resize(fr.len);

		if (buf.size() == 2UL * n) {
			out.emplace_back(buf);
			continue;
		}

		if (fr.state == TRY_L) {
			stack.push_back(Frame{
				.open = fr.open,
				.close = fr.close,
				.len = fr.len,
				.state = TRY_R
			});

			if (fr.open < n) {
				// Create left child by appending '(' to the buffer.
				buf.push_back('(');
				stack.push_back(Frame{
					.open = fr.open + 1,
					.close = fr.close,
					.len = buf.size(),
					.state=TRY_L
				});
			}
			continue;
		}

		if (fr.state == TRY_R) {
			stack.push_back(Frame{
				.open = fr.open,
				.close = fr.close,
				.len = fr.len,
				.state = DONE
			});

			if (fr.close < fr.open) {
				// Create right child by appending '(' to the buffer.
				buf.push_back(')');
				stack.push_back(Frame{
					.open = fr.open,
					.close = fr.close + 1,
					.len = buf.size(),
					.state = TRY_L
				});
			}
			continue;
		}

		// DONE: nothing to do for this problem. If you had postorder work,
		// it would run here, with buf already restored to fr.len.
	}

	return out;
}