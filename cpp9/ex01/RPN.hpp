/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:26:47 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/13 17:49:21 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

# include "colors.hpp"

using	std::cout;
using	std::endl;
using	std::stack;
using	std::string;

class	RPN {
	public:
		class	InvalidExpression : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class	DivisionByZero : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		RPN( string const &str );
	private:
		stack<int>	_nbStack;
		void		doOp( char op );
};

#endif