/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:02:10 by mvoisin           #+#    #+#             */
/*   Updated: 2025/04/16 17:37:13 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout <<  _type << GREEN" created !" << RESET << endl;
}


Ice::Ice( Ice const &rhs ) : AMateria(rhs) {
	*this = rhs;
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout <<  _type << GREEN" created by copy !" << RESET << endl;
}


Ice	&Ice::operator=( Ice const &rhs ) {
	if (this != &rhs)
		_type = rhs._type;
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout <<  _type << GREEN" assignation operator called !" << RESET << endl;
	return (*this);
}

Ice::~Ice( void ) {
		cout << BOLD_RED << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
		cout <<  _type << RED" destroyed !" << RESET << endl;
}


AMateria	*Ice::clone( void ) const {
	return (new Ice(*this));
}

void		Ice::use( ICharacter &target ) {
	cout << BOLD_BLUE << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout << BLUE << "* shoots an ice bolt at " RESET UNDERLINE_WHITE<< target.getName() << BLUE" *" << RESET << endl;
}