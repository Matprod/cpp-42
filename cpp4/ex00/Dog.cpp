/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:19:13 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/16 15:39:10 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	cout << BOLD_BLUE"Random Dog " << RESET << "created by default !" << endl;
	_type = "Dog";
	_name = "Random Dog";
}

Dog::Dog(string name) : Animal(name){
	cout << BOLD_BLUE"Dog :" << RESET << name << " created" << endl;
	_type = "Dog";
}

Dog::Dog(Dog const &src) : Animal(src)
{
	_type = src._type;
	_name = src._name;
	*this = src;
	cout << BOLD_BLUE"Dog " RESET << _name << " created by copy" << endl;
}
Dog &Dog::operator=(Dog const &src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	_name = src._name;
	return (*this);
}
Dog::~Dog(){
		cout << BOLD_BLUE"Dog : " << RESET << "destroyed" << endl;
}

string	Dog::getType() const {
	return (_type);
}

string	Dog::getName() const {
	return (_name);
}

void	Dog::makeSound( void ) const {
	cout << BOLD_BLUE"Dog " << RESET << _name << ": \033[3m *BARK BARK WOUAF WOUAF*" << endl;
}