/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:16:12 by abelov            #+#    #+#             */
/*   Updated: 2025/09/16 15:16:12 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solution.hpp"

int MinStack::getMin() const
{
	return _min.back();
}

int MinStack::top() const
{
	return (_stack.back());
}

void MinStack::pop()
{
	if (_stack.empty()) return;
	int i = _stack.back();
	_stack.pop_back();
	if (!_min.empty() && i == _min.back())
		_min.pop_back();
}

void MinStack::push(int val)
{
	_stack.push_back(val);
	if (_min.empty() || _min.back() >= val)
		_min.push_back(val);
}
