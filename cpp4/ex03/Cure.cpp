/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:29:40 by mvoisin           #+#    #+#             */
/*   Updated: 2025/04/16 17:37:24 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout <<  _type << GREEN" created !" << RESET << endl;
}

Cure::Cure( Cure const &rhs ) : AMateria(rhs) {
	*this = rhs;
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout <<  _type << GREEN" created by copy !" << RESET << endl;
}


Cure	&Cure::operator=( Cure const &rhs ) {
	if (this != &rhs)
		_type = rhs._type;
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout <<  _type << GREEN" assignation operator called !" << RESET << endl;
	return (*this);
}

Cure::~Cure( void ) {
		cout << BOLD_RED << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
		cout <<  _type << RED" destroyed !" << RESET << endl;
}

AMateria	*Cure::clone( void ) const {
	return (new Cure(*this));
}

void		Cure::use( ICharacter &target ) {
	cout << BOLD_BLUE << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout << BLUE << "* heals " RESET UNDERLINE_WHITE << target.getName() << " wounds *"  << BLUE" *" << RESET << endl;
}