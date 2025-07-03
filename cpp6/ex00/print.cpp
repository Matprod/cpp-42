/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:11:35 by mvoisin           #+#    #+#             */
/*   Updated: 2025/05/16 18:25:35 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.hpp"

size_t	getMaxLen( string const &str, char c, int i, double f ) {
	size_t	maxLen = (str.length() > 3) ? str.length() : str.length() + 3;
	size_t	fLen = 0;

	std::stringstream ss;
	ss << f;
	fLen = ss.str().length();		
	if (f == static_cast<float>(i))
		fLen += 3;
	else
		fLen += 1;
	if (i > 127 || i < 0)
		maxLen = (maxLen > 10) ? maxLen : 10;
	else if (!isprint(c))
		maxLen = (maxLen > 15) ? maxLen : 15;
	if (f > INT_MAX || f < INT_MIN)
		maxLen = (maxLen > 10) ? maxLen : 10;
	if (fLen > maxLen)
		maxLen = fLen;
	if (fLen == 14)
		maxLen = 14;
	else if (fLen == 12)
		maxLen = 12;
	return (maxLen);
}

void	printHighLine( size_t maxLen ) {
	cout << CYAN << "╔";
	for (size_t i = 0; i < maxLen + 10; i++)
		cout << "═";
	cout << "╗" << RESET << endl;
}

void	printLowLine( size_t maxLen ) {
	cout << CYAN << "╚";
	for (size_t i = 0; i < maxLen + 10; i++)
		cout << "═";
	cout << "╝" << RESET << endl;
}

static bool	is_overflow_from_float(string str) {
	char	*endptr = NULL;
	long	iValue = std::strtol(str.c_str(), &endptr, 10);

	if (endptr == str.c_str() || (*endptr != '\0' && *endptr != 'f' && *endptr != 'F' && *endptr != '.'))
		return (true);
	if (iValue > INT_MAX || iValue < INT_MIN)
		return (true);
	return (false);
}

void print_char(int i, char c, size_t maxLen) {
	cout << R_WALL << BLUE << std::setw(8) << "char: ";
	if (i > 127 || i < 0)
		cout << BOLD_RED << setw(maxLen) << left << "Impossible" << L_WALL << RESET << endl;
	else if (!isprint(c))
		cout << BOLD_RED << setw(maxLen) << left << "Non displayable" << L_WALL << RESET << endl;
	else
		cout << BOLD_GREEN << setw(maxLen) << left << c << L_WALL << RESET << endl;
}

void print_int(string const &str, int i, size_t maxLen) {
	cout << R_WALL << BLUE << setw(8) << right << "int: ";
	if (is_overflow_from_float(str))
		cout << BOLD_RED << setw(maxLen) << left << "Impossible" << L_WALL << RESET << endl;
	else
		cout << BOLD_GREEN << setw(maxLen) << left << i << L_WALL << RESET << endl;
}

void	print_float(int i, float f, size_t maxLen) {
	cout << R_WALL << BLUE << setw(8) << right << "float: ";
	if (f == static_cast<float>(i)) {
		std::stringstream	ss;
		ss << f << ".0f";
		string	fStr = ss.str();
		cout << BOLD_GREEN << setw(maxLen) << left << fStr << L_WALL << RESET << endl;
	} else {
		std::stringstream	ss;
		ss << f << "f";
		string	fStr = ss.str();
		cout << BOLD_GREEN << setw(maxLen) << left << fStr << L_WALL << RESET << endl;
	}
}

void	print_double(int i, double d, size_t maxLen) {
	cout << R_WALL << BLUE << setw(8) << right << "double: ";
	if (d == static_cast<double>(i)) {
		std::stringstream	ss;
		ss << d << ".0";
		string	dStr = ss.str();
		cout << BOLD_GREEN << setw(maxLen) << left << dStr << L_WALL << RESET << endl;
	} else
		cout << BOLD_GREEN << setw(maxLen) << left << d << L_WALL << RESET << endl;
}


void	printAll( char c, int i, float f, double d, string const &str ) {
	size_t	maxLen = getMaxLen(str, c, i, d);
	
	printHighLine(maxLen);
	print_char(i, c, maxLen);
	print_int(str, i, maxLen);
	print_float(i, f, maxLen);
	print_double(i, d, maxLen);
	printLowLine(maxLen);
}