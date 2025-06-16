/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:26:29 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/13 17:49:44 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( string const &str ) : _nbStack() {
	if (str.find_first_of("0123456789") == string::npos || str.find_first_of("0123456789") == str.find_last_of("0123456789"))
		throw (InvalidExpression());
	for (size_t i = 0; i < str.size(); ++i) {
		if (std::isdigit(str[i]) || str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '/') {
			if ((i && str[i - 1] != ' ') || (i + 1 < str.size() && str[i + 1] != ' ')) {
				throw (InvalidExpression());
			}
			if (std::isdigit(str[i]))
				_nbStack.push(str[i] - '0');
			else if (_nbStack.size() < 2)
				throw (InvalidExpression());
			else
				doOp(str[i]);
		} else if (str[i] != ' ')
			throw (InvalidExpression());
	}
	if (_nbStack.size() != 1)
		throw (InvalidExpression());
	cout << BOLD_GREEN"[RESULT] " GREEN << _nbStack.top() << RESET << endl;
}

void	RPN::doOp( char op ) {
	int	first;
	int	second;

	second = _nbStack.top();
	_nbStack.pop();
	first = _nbStack.top();
	_nbStack.pop();

	switch (op) {
		case '+':
			_nbStack.push(first + second);
			break;
		case '-':
			_nbStack.push(first - second);
			break;
		case '*':
			_nbStack.push(first * second);
			break;
		default:
			if (second == 0)
				throw (DivisionByZero());
			_nbStack.push(first / second);
			break;
			throw (InvalidExpression());
	}
}

const char*	RPN::InvalidExpression::what() const throw() {
	return (BOLD_RED"[ERROR] " RED"Invalid expression !");
}

const char*	RPN::DivisionByZero::what() const throw() {
	return (BOLD_RED"[ERROR] " RED"Division by zero !");
}