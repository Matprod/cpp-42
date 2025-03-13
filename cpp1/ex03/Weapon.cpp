/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:14:26 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/09 20:42:53 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const string	&Weapon::getType(){
	return (_type);
}

void	Weapon::setType(string type){
	std::cout << "\033[1;35mWeapon: \033[0;35m" << _type << " is now " << type << "!\033[0m" << std::endl;
	this->_type = type;
}

Weapon::Weapon(std::string type) : _type(type){
	std::cout << "\033[1;32mWeapon: \033[0;32m" << _type << " created !\033[0m" << std::endl;
}

Weapon::Weapon() : _type("Unknown Weapon"){
	std::cout << "\033[1;32mWeapon: \033[0;32m" << _type << " created !\033[0m" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "\033[1;31mWeapon: \033[0;31m" << _type << " destroyed !\033[0m" << std::endl;
}