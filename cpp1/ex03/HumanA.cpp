/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:47:19 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/09 21:29:23 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack(void) {
	std::cout << "\033[1;33m" <<_name << "\033[0;33m attacks with " << this->_weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {
	std::cout << "\033[1;32mHuman A: \033[0;32m" << _name << " created with " << _weapon.getType() << " as weapon !\033[0;m" << std::endl;
}

HumanA::~HumanA() {
	std::cout << "\033[1;31mHuman A: \033[0;31m" << _name << " destroyed !\033[0m" << std::endl;
}