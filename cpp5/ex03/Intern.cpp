/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:27:04 by Matprod           #+#    #+#             */
/*   Updated: 2025/07/03 17:51:23 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {
	cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created by default" RESET << endl;
}

Intern::Intern( Intern const &rhs ) {
	cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created by copy" RESET << endl;
	*this = rhs;
}

Intern	&Intern::operator=( Intern const &rhs ) {
	cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created by assignation" RESET << endl;
	(void)rhs;
	return *this;
}

Intern::~Intern( void ) {
	cout << BOLD_RED "[" << typeid(*this).name() + 1 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << RED" destroyed" RESET << endl;
}

const char	*Intern::FormNotFoundException::what() const throw() {
	return (BOLD_RED "[Intern] " RED"Form not found" RESET);
}

AForm	*Intern::makeForm( string name, string target ) {
	int index = -1;
	string formName[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	for (int i = 0; i < 3; i++) {
		if (name == formName[i])
			index = i;
	}
	switch(index) {
		case 0:	
			return new RobotomyRequestForm(target);
		case 1:
			return new PresidentialPardonForm(target);
		case 2:
			return new ShrubberyCreationForm(target);	
		case -1:
			throw Intern::FormNotFoundException();
	}
	return NULL;
}