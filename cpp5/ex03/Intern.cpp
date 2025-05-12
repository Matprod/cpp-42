/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:27:04 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/29 15:16:39 by Matprod          ###   ########.fr       */
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
	cout << RESET UNDERLINE_WHITE << _name << GREEN" acreated by assignation" RESET << endl;
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
	AForm	*ret = NULL;

	string formName[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	AForm	*form[3] = {
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target),
		new ShrubberyCreationForm(target)
	};
	for (int i = 0; i < 3; i++) {
		if (name == formName[i])
			ret = form[i];
		else
			delete form[i];
	}
	if (ret == NULL)
		throw Intern::FormNotFoundException();
	return ret;
}