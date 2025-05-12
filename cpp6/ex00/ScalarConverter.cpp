/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:04:34 by Matprod           #+#    #+#             */
/*   Updated: 2025/05/11 20:07:36 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const string& literal) {
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

static bool isInt(const string& literal) {
	std::istringstream iss(literal);
	int num;
	iss >> num;
	return (!iss.fail() && iss.eof());
}

static bool isFloat(const string& literal) {
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;
	if (literal[literal.length() - 1] != 'f')
		return false;
	std::istringstream iss(literal.substr(0, literal.length() - 1));
	float num;
	iss >> num;
	return (!iss.fail() && iss.eof());
}

static bool isDouble(const string& literal) {
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	std::istringstream iss(literal);
	double num;
	iss >> num;
	return (!iss.fail() && iss.eof());
}

static void printChar(double value) {
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(value))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
}

static void printInt(double value) {
	if (std::isnan(value) || std::isinf(value) ||
		value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

static void printFloat(float value) {
	if (std::isnan(value)) {
		std::cout << "float: nanf" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << "float: " << (value < 0 ? "-inff" : "+inff") << std::endl;
	} else {
		std::cout << "float: " << value;
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

static void printDouble(double value) {
	if (std::isnan(value)) {
		std::cout << "double: nan" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << "double: " << (value < 0 ? "-inf" : "+inf") << std::endl;
	} else {
		std::cout << "double: " << value;
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void ScalarConverter::convert(const string& literal) {
	double value = 0.0;
	bool isValid = true;

	if (isChar(literal)) {
		value = static_cast<double>(literal[0]);
	} else if (isInt(literal)) {
		std::istringstream iss(literal);
		iss >> value;
	} else if (isFloat(literal)) {
		if (literal == "nanf") {
			value = std::numeric_limits<double>::quiet_NaN();
		} else if (literal == "-inff") {
			value = -std::numeric_limits<double>::infinity();
		} else if (literal == "+inff") {
			value = std::numeric_limits<double>::infinity();
		} else {
			std::istringstream iss(literal.substr(0, literal.length() - 1));
			iss >> value;
		}
	} else if (isDouble(literal)) {
		if (literal == "nan") {
			value = std::numeric_limits<double>::quiet_NaN();
		} else if (literal == "-inf") {
			value = -std::numeric_limits<double>::infinity();
		} else if (literal == "+inf") {
			value = std::numeric_limits<double>::infinity();
		} else {
			std::istringstream iss(literal);
			iss >> value;
		}
	} else {
		isValid = false;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}

	if (isValid) {
		printChar(value);
		printInt(value);
		printFloat(static_cast<float>(value));
		printDouble(value);
	}
}