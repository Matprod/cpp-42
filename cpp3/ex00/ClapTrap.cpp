/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:26:56 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 14:10:46 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(string name): _name(name){
	cout << "\033[0;32mClapTrap : \033[1;32m" << name << "\033[0;m called " << std::endl << std::endl;
	_hit_point = CLAP_HIT_POINT;
	_energy_point = CLAP_ENERGY_POINT;
	_attack_damage = CLAP_ATTACK_DAMAGE;
	_max_hit_point = CLAP_HIT_POINT;
}
ClapTrap::ClapTrap(){
	std::cout << "ClapTrap default constructor called\n";
	_hit_point = CLAP_HIT_POINT;
	_energy_point = CLAP_ENERGY_POINT;
	_attack_damage = CLAP_ATTACK_DAMAGE;
	_max_hit_point = CLAP_HIT_POINT;
}

ClapTrap::ClapTrap(ClapTrap const &src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap	&ClapTrap::operator=( ClapTrap const & rhs ) {
	if (this == &rhs)
		return (*this);
	_name = rhs._name;
	_hit_point = rhs._hit_point;
	_energy_point = rhs._energy_point;
	_attack_damage = rhs._attack_damage;
	_max_hit_point = rhs._max_hit_point;
	std::cout << "\033[0;32mClaptrap\033[0;m" << _name << " created by assignement!" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(){
	cout << "\033[0;32mClapTrap : \033[1;32m" << _name << "\033[0;m destroyed " << std::endl;
}


void ClapTrap::attack(const std::string& target){
	if (this->_energy_point > 0)
	{
		cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m attacks " << target << " causing \033[1;31m"  << this->_attack_damage << "\033[0;m damage!" << std::endl;
		this->_energy_point--;
	}
	else
		cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m has no \033[1;35menergy point\033[0;m and can't attack !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hit_point > 0 && this->_hit_point - (int)amount <= 0)
	{
		this->_hit_point = 0;
		cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m take \033[1;31m" << amount << "\033[0;m damage and is now \033[1;31mknockout\033[0;m" << std::endl;
		cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m has now \033[1;31m" << this->_hit_point << "\033[0;m hit points !" << std::endl;

	}
	else if (this->_hit_point < 0)
	{
		cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << " is already knockout" << std::endl;
		cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m has now \033[1;31m" << this->_hit_point << "\033[0;m hit points !" << std::endl;

	}
	else if (this->_hit_point - (int)amount > 0)
	{
		this->_hit_point -= (int)amount;
		cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m take \033[1;31m" << amount << "\033[0;m damage !" << std::endl;
		cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m has now \033[1;31m" << this->_hit_point << "\033[0;m hit points !" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energy_point > 0)
	{
		if (this->_energy_point + (int)amount >= CLAP_HIT_POINT)
		{
			this->_hit_point = CLAP_HIT_POINT;
			cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m \033[1;34m repaired himself with magic\033[0;m and has gain \033[1;31m" << amount << "\033[0;m hit points" << std::endl;
			cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m has now \033[1;31m" << this->_hit_point << "\033[0;m hit points !" << std::endl;
		}
		else
		{
			this->_hit_point += (int)amount;
			cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m \033[1;34mrepaired himself with magic\033[0;m and has gain \033[1;31m" << amount << "\033[0;m hit points" << std::endl;
			cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m has now \033[1;31m" << this->_hit_point << "\033[0;m hit points !" << std::endl;
		}
		if (this->_hit_point == CLAP_HIT_POINT)
			cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m is now \033[1;33mfull\033[0;m of hit point" << std::endl;
		this->_energy_point--;
	}
	else
		cout << "\033[0;32mClapTrap : \033[1;32m" << this->_name << "\033[0;m has no \033[1;35menergy point\033[0;m and can't repair himself !" << std::endl;
}