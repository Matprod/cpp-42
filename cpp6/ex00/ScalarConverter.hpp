/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:05:06 by Matprod           #+#    #+#             */
/*   Updated: 2025/05/16 19:21:13 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <limits>
#include <cctype>
#include <cmath>
#include <string>

#include "getType.hpp"
#include "converter.hpp"

typedef std::string string;

class ScalarConverter {
public:
	static void convert(char *str);

private:
	~ScalarConverter();
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
};

