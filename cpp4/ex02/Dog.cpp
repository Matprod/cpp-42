/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:19:13 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/02 14:18:28 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	cout << BOLD_BLUE"Random Dog " << RESET << "created by default !" << endl;
	_type = "Dog";
	_name = "Random Dog";
	_brain = new Brain();
}

Dog::Dog(string name) : Animal(name){
	cout << BOLD_BLUE"Dog :" << RESET << name << "created" << endl;
	_type = "Dog";
	_brain = new Brain();
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
	if (this != &rhs)
	{
		_type = rhs.getType();
		_name = rhs.getName();
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}
Dog::~Dog(){
	delete _brain;
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

void	Dog::addIdea( string idea ) const {
	_brain->addIdea(idea);
}


void	Dog::printIdeas( void ) const {
	_brain->printIdeas();
}