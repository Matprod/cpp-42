/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:26:34 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 16:49:39 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(){
	cout << BOLD_CYAN"Random WrongCat " << RESET << "created by default !" << endl;
	_type = "WrongCat";
	_name = "Random WrongCat";
}

WrongCat::WrongCat(string name) : WrongAnimal(name){
	cout << BOLD_CYAN"WrongCat :" << RESET << name << "created" << endl;
	_type = "WrongCat";
	_name = name;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	_type = src._type;
	_name = src._name;
	*this = src;
	cout << BOLD_CYAN"WrongCat " RESET << _name << " created by copy" << endl;
}
WrongCat &WrongCat::operator=(WrongCat const &src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	_name = src._name;
	return (*this);
}
WrongCat::~WrongCat(){
		cout << BOLD_CYAN"WrongCat : " << RESET << "destroyed" << endl;
}

string	WrongCat::getType() const {
	return (_type);
}

string	WrongCat::getName() const {
	return (_name);
}
void	WrongCat::makeSound( void ) const {
	cout << BOLD_CYAN"WrongCat " << RESET << _name << ": \033[3m *meuuuuuuuuuuuuuuuuuh*" << endl;
}