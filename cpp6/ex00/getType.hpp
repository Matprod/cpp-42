/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getType.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:01:04 by mvoisin           #+#    #+#             */
/*   Updated: 2025/05/16 15:33:39 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <cstdlib>
# include <cfloat>
# include <climits>
# include <limits>
# include <iomanip>
# include <sstream>

#define CHAR 0 
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define NAN_OR_INF 4

typedef std::string string;

int getType(string const &str);
bool isChar(string const &str);
bool isInt(string const &str);
bool isFloat(string const &str);
bool isDouble(string const &str);
bool isNanOrInf(string const &str);

#define ERROR 5