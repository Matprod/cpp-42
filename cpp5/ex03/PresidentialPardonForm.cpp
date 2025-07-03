/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:51:35 by Matprod           #+#    #+#             */
/*   Updated: 2025/07/03 17:42:34 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5), _target("default") {
	cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created by default" RESET << endl;
}

PresidentialPardonForm::PresidentialPardonForm(string target) : AForm("PresidentialPardonForm", 25, 5) {
	_target = target;
	cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created" RESET << endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &rhs ) : AForm(rhs) {
	_target = rhs._target;
	cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created by copy" RESET << endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs ) {
	if (this != &rhs) {
		_target = rhs._target;
	}
	cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created by assignation" RESET << endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	cout << BOLD_RED "[" << typeid(*this).name() + 2 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << RED" destroyed" RESET << endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);
	cout << BOLD_BLUE << _target << " has been pardoned by Zafod Beeblebrox" << RESET << endl;
}