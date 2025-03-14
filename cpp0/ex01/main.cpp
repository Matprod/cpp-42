/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:12:21 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/12 18:58:17 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main() {
	PhoneBook	book;
	string		input;
	
	while (1)
	{
		std::cout << "Enter a command (\033[1;33mADD\033[m, \033[1;33mSEARCH\033[m, \033[1;33mEXIT\033[m) : ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "EXIT")
			exit(0);
		else if (input == "ADD")
			book.add();
		else if (input == "SEARCH")
			book.search();
		else
			std::cout << "Invalid command this PhoneBook works only with \033[1;33mADD\033[m/\033[1;33mSEARCH\033[m/\033[1;33mEXIT\033[m" << std::endl;
	}
	return (0);
}