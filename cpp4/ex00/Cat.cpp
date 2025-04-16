/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:26:34 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/16 15:39:24 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	cout << BOLD_MAGENTA"Random Cat " << RESET << "created by default !" << endl;
	_type = "Cat";
	_name = "Random Cat";
}

Cat::Cat(string name) : Animal(name){
	cout << BOLD_MAGENTA"Cat :" << RESET << name << " created" << endl;
	_type = "Cat";
	_name = name;
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
	if (this == &src)
		return (*this);
	_type = src._type;
	_name = src._name;
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