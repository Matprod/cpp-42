/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:25:35 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/13 17:48:39 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(string const &dataBase){
	std::ifstream	file;
	string			date;
	string			line;
	float			price;
	int				pos;

	file.open(dataBase.c_str());
	if (file.fail())
		throw BitcoinExchange::FileOpenException();; 
	while (getline(file, line))
	{
		pos = line.find(",");
		date = line.substr(0, pos);
		price = atof(line.substr(pos +1).c_str());
		_prices[date] = price;
	}
	file.close();
}

void	BitcoinExchange::getExchange( string const &line ) {
	string		date;
	string		closestDate;
	string		tmp;
	float		value;

	if (line.find('|') == string::npos)
		throw BitcoinExchange::WrongFormatException();
	date = line.substr(0, line.find('|') - 1);
	if (!isValidDate(date))
		throw BitcoinExchange::InvalideDateException();
	closestDate = getClosestDate(date);
	tmp = line.substr(line.find('|') + 2);
	if (tmp.find_last_not_of("0123456789.") != string::npos || tmp.find('.') != tmp.find_last_of('.')
		|| tmp.find_first_of("0123456789") > 0)
		throw BitcoinExchange::WrongFormatException();
	value = atof(line.substr(line.find('|') + 2).c_str());
	if (value < 0)
		throw BitcoinExchange::NegativeValueException();
	else if (value > 1000)
		throw BitcoinExchange::TooHighValueException();
	std::cout << BOLD_GREEN"[INFO] " GREEN "The exchange rate on " << date << " was " << _prices[closestDate] * value << "$." << RESET << std::endl;
}

#include <iostream>
#include <string>
#include <cstdlib> 

bool isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}


string	BitcoinExchange::getClosestDate( string const &date ) {
	string	closestDate;
	int		year;
	int		month;
	int		day;
	int		yearClosest;
	int		monthClosest;
	int		dayClosest;
	int		diff = INT_MAX;

	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 2).c_str());
	day = atoi(date.substr(8, 2).c_str());

	for (map<string, float>::iterator it = _prices.begin(); it != _prices.end(); it++) {
		yearClosest = atoi(it->first.substr(0, 4).c_str());
		monthClosest = atoi(it->first.substr(5, 2).c_str());
		dayClosest = atoi(it->first.substr(8, 2).c_str());
		if (abs(yearClosest - year) * 365 + abs(monthClosest - month) * 30 + abs(dayClosest - day) < diff) {
				diff = abs(yearClosest - year) * 365 + abs(monthClosest - month) * 30 + abs(dayClosest - day);
				closestDate = it->first;
			}
		}
	return (closestDate);
}

bool isValidDate(const std::string& date) {
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	int year  = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day   = atoi(date.substr(8, 2).c_str());
	
	if (month < 1 || month > 12)
		return false;

	if (isLeapYear(year))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

const char	*BitcoinExchange::FileOpenException::what() const throw() {
	return (BOLD_RED"[ERROR] " RED "File could not be opened !" RESET);
}

const char	*BitcoinExchange::WrongFormatException::what() const throw() {
	return (BOLD_RED"[ERROR] " RED "Wrong format !" RESET);
}

const char	*BitcoinExchange::NegativeValueException::what() const throw() {
	return (BOLD_RED"[ERROR] " RED "Negative price !" RESET);
}

const char	*BitcoinExchange::InvalideDateException::what() const throw() {
	return (BOLD_RED"[ERROR] " RED "Invalid date found !" RESET);
}

const char	*BitcoinExchange::TooHighValueException::what() const throw() {
	return (BOLD_RED"[ERROR] " RED "Too high price !" RESET);
}