/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:02:55 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/12 23:12:38 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

Harl::Harl() {
	std::cout << "\033[1;32mHarl created with success !\033[0m" << std::endl; 
}

Harl::~Harl() {
	std::cout << "\033[1;31mHarl destroyed with success !\033[0m" << std::endl; 
}

void	Harl::_debug(void) {
	std::cout << "\033[1;35m[DEBUG]\033[0;35m" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\033[0m" << std::endl;
}

void	Harl::_info(void) {
	std::cout << "\033[1;32m[INFO]\033[0;32m" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\033[0m" << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "\033[1;33m[WARNING]\033[0;33m" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\033[0m" << std::endl;
}

void	Harl::_error(void) {
	std::cout << "\033[1;31m[ERROR]\033[0;31m" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now.\033[0m" << std::endl;
}

void	Harl::complain(std::string level) {
	void	(Harl::*function_ptr[4])(void)	= {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string					tab_lvl[4]	= {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (tab_lvl[i] == level)
			(this->*function_ptr[i])();
}