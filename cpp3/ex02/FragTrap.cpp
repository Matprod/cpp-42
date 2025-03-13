/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:30:17 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 13:51:30 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hit_point = FRAG_HIT_POINT;
	_energy_point = FRAG_ENERGY_POINT;
	_attack_damage = FRAG_ATTACK_DAMAGE;
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name) {
	cout << "\033[0;32mFragTrap : \033[1;32m" << _name << "\033[0;m create " << std::endl;
	_hit_point = FRAG_HIT_POINT;
	_energy_point = FRAG_ENERGY_POINT;
	_attack_damage = FRAG_ATTACK_DAMAGE;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called\n";
	*this = other;
}

FragTrap	&FragTrap::operator=( FragTrap const & rhs ) {
	if (this == &rhs)
		return (*this);
	_name = rhs._name;
	_hit_point = rhs._hit_point;
	_energy_point = rhs._energy_point;
	_attack_damage = rhs._attack_damage;
	std::cout << "\033[0;32mFragtrap\033[0;m" << _name << " created by assignement!" << std::endl;
	return (*this);
}

FragTrap::~FragTrap() {
	cout << "\033[0;32mFragTrap : \033[1;32m" << _name << "\033[0;m destroyed " << std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << "\033[0;32mFrag trap\033[0;m " << _name << " did a hive fives !" << std::endl;
}