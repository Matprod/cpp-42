/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:48:52 by Matprod           #+#    #+#             */
/*   Updated: 2025/07/03 17:42:42 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
		cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << GREEN" created by default" RESET << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm("ShrubberyCreationForm", 145, 137) {
	_target = target;
		cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << GREEN" created" RESET << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &rhs ) : AForm(rhs) {
	_target = rhs._target;
		cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << GREEN" created by copy" RESET << endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs ) {
	if (this != &rhs) {
		_target = rhs._target;
	}
		cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << GREEN" created by assignation" RESET << endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
		cout << BOLD_RED "[" << typeid(*this).name() + 2 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << RED" destroyed" RESET << endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	char	c;

	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (getSigned() == false)
		throw AForm::NotSignedException();
	else {
		ifstream treeFile("tree");
		if (!treeFile.is_open())
			throw AForm::FileException();

		ofstream shrubberyFile((_target + "_shrubbery").c_str());
		if (!shrubberyFile.is_open())
			throw AForm::FileException();
			
		while (treeFile.get(c)) {
			shrubberyFile << c;
		}

		treeFile.close();
		shrubberyFile.close();
	}
}