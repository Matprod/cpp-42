/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:03:45 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/12 18:55:55 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

string	Contact::get_first_name() {
	return (this->_first_name);
}

string	Contact::get_last_name() {
	return (this->_last_name);
}

string	Contact::get_nickname() {
	return (this->_nickname);
}

string	Contact::get_phone_number() {
	return (this->_phone_number);
}

string	Contact::get_darkest_secret() {
	return (this->_darkest_secret);
}

void	Contact::set_first_name() {
	string	tmp;
	bool	valid = false;
	
	while (!valid)
	{
		std::cout << "Enter a first name : ";
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			exit(0);
		valid = (tmp.empty()) ? false : true;
		if (valid)
			this->_first_name = tmp;
		else
			std::cout << "Invalid input for first name !" << std::endl;
	}
}

void	Contact::set_last_name() {
	string	tmp;
	bool	valid = false;
	
	while (!valid)
	{
		std::cout << "Enter a last name : ";
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			exit(0);
		valid = (tmp.empty()) ? false : true;
		if (valid)
			this->_last_name = tmp;
		else
			std::cout << "Invalid input for last name !" << std::endl;
	}
}

void	Contact::set_nickname() {
	string	tmp;
	bool	valid = false;
	
	while (!valid)
	{
		std::cout << "Enter a nickname : ";
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			exit(0);
		valid = (tmp.empty()) ? false : true;
		if (valid)
			this->_nickname = tmp;
		else
			std::cout << "Invalid input for nickname !" << std::endl;
	}
}

void	Contact::set_phone_number() {
	string	tmp;
	bool	valid = false;
	
	while (!valid)
	{
		std::cout << "Enter a phone number : ";
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			exit(0);
		valid = (tmp.empty()) ? false : true;
		if (valid)
			this->_phone_number = tmp;
		else
			std::cout << "Invalid input for phone number !" << std::endl;
	}
}

void	Contact::set_darkest_secret() {
	string	tmp;
	bool	valid = false;
	
	while (!valid)
	{
		std::cout << "Enter a darkest secret : ";
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			exit(0);
		valid = (tmp.empty()) ? false : true;
		if (valid)
			this->_darkest_secret = tmp;
		else
			std::cout << "Invalid input for darkest secret !" << std::endl;
	}
}

void	Contact::show_contact(int id) {
	std::cout << "\033[1;32mId            : " << id << std::endl;
	std::cout << "First Name    : " << this->get_first_name() << std::endl;
	std::cout << "Last Name     : " << this->get_last_name() << std::endl;
	std::cout << "Nickname      : " << this->get_nickname() << std::endl;
	std::cout << "Phone number  : " << this->get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << this->get_darkest_secret() << "\033[m" << std::endl;
}

void	Contact::print_trunc(string str) {
	if (str.length() > 10)
		std::cout << std::setw(9) << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}