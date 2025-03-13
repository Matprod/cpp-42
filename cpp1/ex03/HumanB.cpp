/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:24:43 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/11 14:02:31 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack() {
	std::string	weapon_name = _weapon ? _weapon->getType() : "bare hand";
	std::cout << "\033[1;33m" << this->_name << "\033[0;33m attacks with their " << weapon_name << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

HumanB::HumanB(std::string name): _name(name), _weapon(NULL){
	std::cout << "\033[1;32mHuman B: \033[0;32m" << _name << " created without weapon !\033[0;m" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "\033[1;31mHuman B: \033[0;31m" << _name << " destroyed !\033[0m" << std::endl;
}