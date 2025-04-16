/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:28:49 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/16 15:39:16 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	cout << BOLD_YELLOW"Random Animal " << RESET << "created by default !" << endl;
	_type = "Animal";
	_name = "Random animal";
}

Animal::Animal(string name){
	_name = name;
	cout << BOLD_YELLOW"Animal :" << RESET << name << " created" << endl;
	_type = "Animal";
}

Animal::Animal(Animal const &src)
{
	_type = src._type;
	_name = src._name;
	*this = src;
	cout << BOLD_YELLOW"Animal " RESET << _name << " created by copy" << endl;
}
Animal &Animal::operator=(Animal const &src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	_name = src._name;
	return (*this);
}
Animal::~Animal(){
		cout << BOLD_YELLOW"Animal : " << this->_name << RESET << " destroyed" << endl;
}

string	Animal::getType() const {
	return (_type);
}

string	Animal::getName() const {
	return (_name);
}

void	Animal::makeSound( void ) const {
	cout << BOLD_YELLOW"Animal " << RESET << _name << ": \033[3m *animal making noises*" << endl;
}