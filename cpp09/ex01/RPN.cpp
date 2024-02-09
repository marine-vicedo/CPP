/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:50:16 by mvicedo           #+#    #+#             */
/*   Updated: 2023/12/12 11:16:41 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN:: RPN() {}

RPN::RPN(std::string input) : _input(input)
{
	evalRpnExpression();
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_input = other._input;
		this->_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN() {}

bool RPN:: isOperator(char &elem) const
{
	if (elem == '+' || elem == '-' || elem == '*' || elem == '/')
		return true;
	return false;
}

void RPN::evaluateOperation(char &op)
{
	if (_stack.size() < 2) {
		throw std::invalid_argument("Invalid input, not enough numbers");
	}

	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();

	int result;
	switch (op) {
		case '+':
			result = b + a;
			break;
		case '-':
			result = b - a;
			break;
		case '*':
			result = b * a;
			break;
		case '/':
			if (a == 0)
				throw std::invalid_argument("Invalid input, division by 0");
			result = b / a;
			break;
		default:
			throw std::invalid_argument("Invalid operator");
	}

	_stack.push(result);
}


void RPN::evalRpnExpression() 
{
	bool hasOperator = false;
	bool hasNumber = false;

	for (size_t i = 0; i < _input.length(); ++i)
	{
		char token = _input[i];

		if (token == ' ')
			continue;

		if (isdigit(token))
		{
			_stack.push(token - '0');
			hasNumber = true;
		}
		else if (isOperator(token))
		{
			hasOperator = true;
			evaluateOperation(token);
		} else {
			throw std::invalid_argument("Invalid input, only numbers and operators are allowed");
		}
	}
	if (!hasOperator)
		throw std::invalid_argument("Invalid input, at least one operator is required");
	if (!hasNumber)
		throw std::invalid_argument("Invalid input, at least one number is required");
	if (_stack.size() != 1)
		throw std::invalid_argument("Invalid input, too many numbers");
}

void RPN:: getResult()
{
	std::cout << _stack.top() << std::endl;
}
