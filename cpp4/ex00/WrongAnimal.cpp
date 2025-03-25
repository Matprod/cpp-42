/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:28:49 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 16:49:16 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	cout << BOLD_GREEN"Random WrongAnimal " << RESET << "created by default !" << endl;
	_type = "WrongAnimal";
	_name = "Random Wronganimal";
}

WrongAnimal::WrongAnimal(string name){
	_name = name;
	cout << BOLD_GREEN"WrongAnimal :" << RESET << name << "created" << endl;
	_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	_type = src._type;
	_name = src._name;
	*this = src;
	cout << BOLD_GREEN"WrongAnimal " RESET << _name << " created by copy" << endl;
}
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	_name = src._name;
	return (*this);
}
WrongAnimal::~WrongAnimal(){
		cout << BOLD_GREEN"WrongAnimal : " << this->_name << RESET << " destroyed" << endl;
}

string	WrongAnimal::getType() const {
	return (_type);
}

string	WrongAnimal::getName() const {
	return (_name);
}

void	WrongAnimal::makeSound( void ) const {
	cout << BOLD_GREEN"WrongAnimal " << RESET << _name << ": \033[3m *Wrong Animal making noises*" << endl;
}