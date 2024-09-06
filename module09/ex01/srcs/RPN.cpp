/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:10:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/09/06 04:05:30 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <iostream>

RPN::RPN(void) : _expression("") {}

RPN::~RPN(void) {}

RPN::RPN(std::string const &expression) : _expression(expression) {}

RPN::RPN(RPN const & param) {
	*this = param;
}

RPN	&RPN::operator=(RPN const &param) {
	if (this == &param) {
		_stack = param._stack;
		_expression = param._expression;
	}
	return (*this);
}

void	RPN::resolveRPN(void) {

	if (_expression.empty()) {
		throw std::runtime_error("input void.");
	}

	std::string	token;
	std::stringstream	iss(_expression);

	while (iss >> token) {
		if (std::isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
			int number = atoi(token.c_str());
			if (number > 9 || token.size() > 2) {
				throw std::runtime_error("too long number.");
			} else if (number < 0) {
				throw std::runtime_error("negative number.");
			}
			_stack.push(number);
		} else if (token == "-" || token == "+" || token == "*" \
			|| token == "/") {
			if (_stack.size() < 2) {
				throw std::runtime_error("few operands.");
			}

			int	num2 = _stack.top(); _stack.pop();
			int	num1 = _stack.top(); _stack.pop();

			if (token == "+") {
				_stack.push(num1 + num2);
			} else if (token == "-") {
				_stack.push(num1 - num2);
			} else if (token == "*") {
				_stack.push(num1 * num2);
			} else if (token == "/") {
				if (num2 == 0) {
					throw std::runtime_error("division is not possible.");
				}
				_stack.push(num1 / num2);
			}
		} 
		else {
			throw std::runtime_error("Invalid expression.");
		}
	}
	if (_stack.size() != 1) {
		throw std::runtime_error("expression error.");
	}
}

void	RPN::printRPN(void) {
	try {
		resolveRPN();
		std::cout << GREEN << _stack.top() << DFT << std::endl;
	} catch (std::exception const &e) {
		std::cerr << RED "Error: " << e.what() << DFT << std::endl;
	}
}
