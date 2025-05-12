/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:48:31 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/28 16:48:37 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45), _target("default") {
		cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << GREEN" created by default" RESET << endl;
}

RobotomyRequestForm::RobotomyRequestForm(string target) : AForm("RobotomyRequestForm", 72, 45) {
	_target = target;
		cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << GREEN" created" RESET << endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &rhs ) : AForm(rhs) {
	_target = rhs._target;
		cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << GREEN" created by copy" RESET << endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs ) {
	if (this != &rhs) {
		_target = rhs._target;
	}
		cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << GREEN" acreated by assignation" RESET << endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
		cout << BOLD_RED "[" << typeid(*this).name() + 2 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << RED" destroyed" RESET << endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);
	srand(time(NULL));
	cout << BOLD_BLUE << "* drilling noises *" << RESET << endl;
	if (rand() % 2)
		cout << BOLD_GREEN << _target << " has been robotomized successfully" << RESET << endl;
	else
		cout << BOLD_RED << _target << " robotomization failed" << RESET << endl;
}