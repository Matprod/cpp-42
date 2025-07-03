/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:40:07 by mvoisin           #+#    #+#             */
/*   Updated: 2025/05/16 18:47:54 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.hpp"
void converter(string const &str)
{
	unsigned short	type = getType(str);

	switch (type)
	{
		case CHAR:
			convertFromChar(str);
			break;
		case INT:
			convertFromInt(str);
			break;
		case FLOAT:
			convertFromFloat(str);
			break;
		case DOUBLE:
			convertFromDouble(str);
			break;
		case NAN_OR_INF:
			convertFromNanOrInf(str);
			break;
		default:
			cout << BOLD_RED "[ERROR] " RESET RED "The string is not a number or a valid litteral" << endl;
			break;
	}
}
void	convertFromChar( string const &str ) {
	char	cValue = str[0];
	int		iValue = static_cast<int>(cValue);
	float	fValue = static_cast<float>(iValue);
	double	dValue = static_cast<double>(iValue);

	printAll(cValue, iValue, fValue, dValue, str);
}

void	convertFromInt( string const &str ) {
	char	*endptr = NULL;
	long	iValue = std::strtol(str.c_str(), &endptr, 10);
	char	cValue = 0;
	float	fValue = 0.0f;
	double	dValue = 0.0;

	try
	{
		if (endptr == str.c_str() || *endptr != '\0')
			throw std::invalid_argument("The string is not a number");
		if (iValue > INT_MAX || iValue < INT_MIN)
			throw std::out_of_range("The number is out of range");
	}
	catch (std::exception &e)
	{
		cout << BOLD_RED "[ERROR] " RESET RED << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	cValue = static_cast<char>(iValue);
	fValue = static_cast<float>(iValue);
	dValue = static_cast<double>(iValue);
	printAll(cValue, iValue, fValue, dValue, str);
}

void	convertFromFloat( string const &str ) {
	char	*endptr = NULL;
	float	fValue = std::strtof(str.c_str(), &endptr);
	char	cValue = 0;
	int		iValue = 0;
	double	dValue = 0.0;

	try
	{
		if (endptr == str.c_str() || (*endptr != 'f' && *endptr != 'F'))
			throw std::invalid_argument("The string is not a number");
		if (fValue > FLT_MAX || fValue < -FLT_MAX)
			throw std::out_of_range("The number is out of range");
	}
	catch (std::exception &e)
	{
		cout << BOLD_RED "[ERROR] " RESET RED << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	cValue = static_cast<char>(fValue);
	iValue = static_cast<int>(fValue);
	dValue = static_cast<double>(fValue);
	printAll(cValue, iValue, fValue, dValue, str);
}

void	convertFromDouble( string const &str ) {
	char	*endptr = NULL;
	double	dValue = std::strtod(str.c_str(), &endptr);
	char	cValue = 0;
	int		iValue = 0;
	float	fValue = 0.0f;

	try
	{
		if (endptr == str.c_str() || *endptr != '\0')
			throw std::invalid_argument("The string is not a number");
		if (dValue > DBL_MAX || dValue < -DBL_MAX)
			throw std::out_of_range("The number is out of range");
	}
	catch (std::exception &e)
	{
		cout << BOLD_RED "[ERROR] " RESET RED << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	cValue = static_cast<char>(dValue);
	iValue = static_cast<int>(dValue);
	fValue = static_cast<float>(dValue);
	printAll(cValue, iValue, fValue, dValue, str);
}

void	convertFromNanOrInf( string const &str ) {
	cout << CYAN << "╔════════════════════╗" << endl;
	cout << R_WALL << BLUE << "  char: " << BOLD_RED << "Impossible" << L_WALL << endl;
	cout << R_WALL << BLUE << "   int: " << BOLD_RED << "Impossible" << L_WALL << endl;
	if (str == "nan" || str == "nanf") {
		cout << R_WALL << BLUE << " float: " << BOLD_GREEN << "nanf      " << L_WALL << endl;
		cout << R_WALL << BLUE << "double: " << BOLD_GREEN << "nan       " << L_WALL << endl;
	}else if (str == "+nan" || str == "+nanf") {
		cout << R_WALL << BLUE << " float: " << BOLD_GREEN << "+nanf     " << L_WALL << endl;
		cout << R_WALL << BLUE << "double: " << BOLD_GREEN << "+nan      " << L_WALL << endl;
	} else if (str == "-nan" || str == "-nanf") {
		cout << R_WALL << BLUE << " float: " << BOLD_GREEN << "-nanf     " << L_WALL << endl;
		cout << R_WALL << BLUE << "double: " << BOLD_GREEN << "-nan      " << L_WALL << endl;
	} else if (str == "inf" || str == "inff") {
		cout << R_WALL << BLUE << " float: " << BOLD_GREEN << "inff      " << L_WALL << endl;
		cout << R_WALL << BLUE << "double: " << BOLD_GREEN << "inf       " << L_WALL << endl;
	}else if (str == "+inf" || str == "+inff") {
		cout << R_WALL << BLUE << " float: " << BOLD_GREEN << "+inff     " << L_WALL << endl;
		cout << R_WALL << BLUE << "double: " << BOLD_GREEN << "+inf      " << L_WALL << endl;
	} else if (str == "-inf" || str == "-inff") {
		cout << R_WALL << BLUE << " float: " << BOLD_GREEN << "-inff     " << L_WALL << endl;
		cout << R_WALL << BLUE << "double: " << BOLD_GREEN << "-inf      " << L_WALL << endl;
	}
	cout << CYAN << "╚════════════════════╝" << RESET << endl;
}