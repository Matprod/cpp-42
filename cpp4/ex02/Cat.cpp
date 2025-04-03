/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:26:34 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/02 14:18:37 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	cout << BOLD_MAGENTA"Random Cat " << RESET << "created by default !" << endl;
	_type = "Cat";
	_name = "Random Cat";
	_brain = new Brain();
}

Cat::Cat(string name) : Animal(name){
	cout << BOLD_MAGENTA"Cat :" << RESET << name << "created" << endl;
	_type = "Cat";
	_name = name;
	_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal(src)
{
	_type = src._type;
	_name = src._name;
	*this = src;
	cout << BOLD_MAGENTA"Cat " RESET << _name << " created by copy" << endl;
}
Cat &Cat::operator=(Cat const &src)
{
	if (this != &rhs)
	{
		_type = rhs.getType();
		_name = rhs.getName();
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}
Cat::~Cat(){
		cout << BOLD_MAGENTA"Cat : " << RESET << "destroyed" << endl;
}

string	Cat::getType() const {
	return (_type);
}

string	Cat::getName() const {
	return (_name);
}
void	Cat::makeSound( void ) const {
	cout << BOLD_MAGENTA"Cat " << RESET << _name << ": \033[3m *GRAOUUUUUUUUUUUUUUUUUUUUUUUUU*" << endl;
}

void	Cat::addIdea( string idea ) const {
	_brain->addIdea(idea);
}

void	Cat::printIdeas( void ) const {
	_brain->printIdeas();
}