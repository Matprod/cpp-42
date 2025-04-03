/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:57:02 by mvoisin           #+#    #+#             */
/*   Updated: 2025/04/03 16:31:20 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(string const &type) : _type(type) {
    cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout << _type << GREEN" created !" << RESET << endl;
}

AMateria::AMateria( const AMateria &rhs ) {
	*this = rhs;
		cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
		cout <<  _type << GREEN" created by copy !" << RESET << endl;
}

AMateria	&AMateria::operator=( const AMateria &rhs ) {
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout << _type << GREEN" created by assignation !" << RESET << endl;
	if (this != &rhs) {
		_type = rhs._type;
	}
	return (*this);
}

AMateria::AMateria(string const &type) : _type(type) {
    cout << BOLD_RED << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout << _type << RED" destroyed!" << RESET << endl;
}

string const	&AMateria::getType() const {
	return (_type);
}

void	AMateria::use(ICharacter& target) {
	cout << BOLD_YELLOW << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout << _type << YELLOW" use on " << target.getName() << endl;
}