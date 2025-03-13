/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:30:17 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 13:47:08 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hit_point = SCAV_HIT_POINT;
	_energy_point = SCAV_ENERGY_POINT;
	_attack_damage = SCAV_ATTACK_DAMAGE;
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name) {
	cout << "\033[0;32mScavTrap : \033[1;32m" << _name << "\033[0;m create " << std::endl;
	_hit_point = SCAV_HIT_POINT;
	_energy_point = SCAV_ENERGY_POINT;
	_attack_damage = SCAV_ATTACK_DAMAGE;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called\n";
	*this = other;
}

ScavTrap	&ScavTrap::operator=( ScavTrap const & rhs ) {
	if (this == &rhs)
		return (*this);
	_name = rhs._name;
	_hit_point = rhs._hit_point;
	_energy_point = rhs._energy_point;
	_attack_damage = rhs._attack_damage;
	_max_hit_point = rhs._max_hit_point;
	std::cout << "\033[0;32mScavtrap\033[0;m" << _name << " created by assignement!" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap() {
	cout << "\033[0;32mScavTrap : \033[1;32m" << _name << "\033[0;m destroyed " << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_energy_point > 0)
	{
		cout << "\033[0;32mScavTrap : \033[1;32m" << "\033[1;32m" << this->_name << "\033[0;m attacks " << target << " causing \033[1;31m"  << this->_attack_damage << "\033[0;m damage!" << std::endl;
		this->_energy_point--;
	}
	else
		cout << "\033[0;32mScavTrap : \033[1;32m" << "\033[1;32m" << this->_name << "\033[0;m has no \033[1;35menergy point\033[0;m and can't attack !" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "\033[0;32mScavTrap : \033[1;32m" << _name << " is now in Gatekeeper mode!\n";
}