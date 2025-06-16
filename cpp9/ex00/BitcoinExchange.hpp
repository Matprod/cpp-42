/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:25:38 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/13 16:28:49 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <cstdlib>
# include <fstream>
# include <map>
# include <climits>
# include "colors.hpp"

using	std::string;
using	std::map;

class BitcoinExchange {

	private:
		BitcoinExchange					( void ) {};
		BitcoinExchange					( BitcoinExchange const &src ) { (void)src; };
		BitcoinExchange 	&operator=	( BitcoinExchange const &rhs ) { (void)rhs; return *this; };
		map<string, float>	_prices;
		map<string, int>	_exchanges;
	public:
		class	FileOpenException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class	WrongFormatException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class	NegativeValueException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class	InvalideDateException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class	TooHighValueException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void			fillBtcPrices	( const string &dataBase );
		string 			getClosestDate	( const string &date );
		void			getExchange		( const string &line );
		BitcoinExchange					( const string &dataBase );
};

bool	isValidDate( string const &date );
