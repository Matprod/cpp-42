/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:00:22 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/03 23:53:49 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


PhoneBook::PhoneBook() {
	this->_nb_contact = 0;
}

void	PhoneBook::add(){
	Contact	contact;

	contact.set_first_name();
	contact.set_last_name();
	contact.set_nickname();
	contact.set_phone_number();
	contact.set_darkest_secret();
	this->_contacts[this->_nb_contact % 8] = contact;
	if (this->_nb_contact != 8)
		this->_nb_contact++;
}

void	PhoneBook::search(){
	string	input;
	int		index;

	if (!this->_nb_contact)
		return ((void)(std::cout << "Any contact in the phone !" << std::endl));
	this->show_full_contact();
	while (1)
	{
		std::cout << "Enter the index of your choice : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		index = std::atoi(input.c_str());
		if (index <= 0 || index > 8 || this->_contacts[index -1].get_first_name().empty())
		{
			std::cout << "Invalid index !" << std::endl;
			std::cout << "Choose index : ";
			for (int i = 0; i < _nb_contact; i++)
			{
				if (i == 0)
					std::cout << i + 1;
				else
					std::cout << " or " << i + 1;
			}
			std::cout << std::endl;
		}
		else
			break;
	}
	this->_contacts[index - 1].show_contact(index);
}

void	PhoneBook::show_full_contact() {
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