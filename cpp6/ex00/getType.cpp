/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getType.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:18:20 by mvoisin           #+#    #+#             */
/*   Updated: 2025/05/16 15:34:34 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getType.hpp"

int	getType( string const &str ) {
	bool			(*checkFunction[5])( string const &str) = {isInt, isChar, isDouble, isFloat, isNanOrInf};
	unsigned short	res[5] = {INT, CHAR, DOUBLE, FLOAT, NAN_OR_INF};

	for (unsigned short i = 0; i < 5; ++i)
		if (checkFunction[i](str))
			return (res[i]);
	return (ERROR);
}

bool	isChar(string const &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return true;
	return false;
}
bool	isInt(string const &str)
{
	if (str.length() == 1 && isdigit(str[0]))
		return true;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}
bool	isFloat(string const &str) {
    bool	decimalFound = false;
	
    for (size_t i = str[0] == '-' || str[0] == '+'; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            if (str[i] == '.' && !decimalFound)
                decimalFound = (true);
            else if (str[i] == 'f' || str[i] == 'F')
                return (i == str.length() - 1);
            else
                return (false);
        }
    }
    return	(decimalFound);
}

bool	isDouble(string const &str) {
	bool	decimalFound = false;
	
    for (size_t i = str[0] == '-' || str[0] == '+'; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            if (str[i] == '.' && !decimalFound)
                decimalFound = (true);
            else
                return (false);
        }
    }
    return	(decimalFound);
}
bool	isNanOrInf(string const &str)
{
	if (str == "nan" || str == "nanf" || str == "+nan" || str == "+nanf" || str == "-nan" || str == "-nanf")
		return true;
	if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return true;
	return false;
}

