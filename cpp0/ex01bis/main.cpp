/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:01:50 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/04 17:11:22 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
	PhoneBook	book;
	string		input;
	
	while (1)
	{
		std::cout << "Enter a command (\033[1;33mADD\033[m, \033[1;33mSEARCH\033[m, \033[1;33mEXIT\033[m) : ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "EXIT")
			return(0);
		else if (input == "SEARCH")
			book.search();
		else if (input == "ADD")
			book.add();
		else
			std::cout << "Enter \033[1;33mADD\033[m/\033[1;33mSEARCH\033[m/\033[1;33mEXIT\033[m" << std::endl;
	}
	return (0);
}