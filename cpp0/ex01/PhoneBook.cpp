/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:03:42 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/12 19:32:29 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->_nb_contact = 0;
}

void	PhoneBook::add() {
	Contact	contact;

	if (this->_nb_contact == 8)
		this->_nb_contact = 0;
	contact.set_first_name();
	contact.set_last_name();
	contact.set_nickname();
	contact.set_phone_number();
	contact.set_darkest_secret();
	this->_contacts[this->_nb_contact] = contact;
	this->_nb_contact ++;
}

void	PhoneBook::search() {
	string	input;
	int		nb;
	
	if (!this->_nb_contact)
		return ((void)(std::cout << "Any contact in the phone !" << std::endl));
	this->show_format_contact();
	while (1)
	{
		std::cout << "Enter the id of the contact you want to see : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		nb = std::atoi(input.c_str());
		if (nb <= 0 || nb > 8 || this->_contacts[nb - 1].get_first_name().empty())
			std::cout << "Invalid index !" << std::endl;
		else
			break ;
	}
	this->_contacts[nb - 1].show_contact(nb);
}



void	PhoneBook::show_format_contact() {
	std::cout << "\033[1;35m╔════════════╦════════════╦════════════╦════════════╗" << std::endl << "║ ";
	std::cout << std::setw(10) << "Id    " << " ║ ";
	std::cout << std::setw(10) << "First Name" << " ║ ";
	std::cout << std::setw(10) << "Last Name " << " ║ ";
	std::cout << std::setw(10) << "Nickname " << " ║ " << std::endl;
	for (int i = 0; i < 8 && !this->_contacts[i].get_first_name().empty(); i++)
	{
		std::cout << "╠════════════╬════════════╬════════════╬════════════╣" << std::endl;
		std::cout << "║ " << std::setw(10) << i + 1 << " ║ ";
		this->_contacts[i].print_trunc(this->_contacts[i].get_first_name());
		std::cout << " ║ ";
		this->_contacts[i].print_trunc(this->_contacts[i].get_last_name());
		std::cout << " ║ ";
		this->_contacts[i].print_trunc(this->_contacts[i].get_nickname());
		std::cout << " ║" << std::endl;
	}
	std::cout << "╚════════════╩════════════╩════════════╩════════════╝\033[m" << std::endl;
}