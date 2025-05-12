/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:54:30 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/28 13:11:24 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ): _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {
		cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << GREEN" created by default" RESET << endl;
}

Form::Form( string name, int gradeToSign, int gradeToExecute ): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToSign < MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > MIN_GRADE)
		throw Form::GradeTooLowException();
	if (_gradeToExecute < MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (_gradeToExecute > MIN_GRADE)
		throw Form::GradeTooLowException();
	cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created" RESET << endl;
}

Form::Form( Form const & src ): _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
	cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created by copy" RESET << endl;
}

Form	&Form::operator=( Form const & rhs ) {
	if (this != &rhs) {
		_signed = rhs._signed;
	}
		cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << GREEN" acreated by assignation" RESET << endl;
	return *this;
}

Form::~Form( void ) {
	cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" destroyed" RESET << endl;
}

string	Form::getName( void ) const {
	return _name;
}

bool	Form::getSigned( void ) const {
	return _signed;
}

int		Form::getGradeToSign( void ) const {
	return _gradeToSign;
}

int		Form::getGradeToExecute( void ) const {
	return _gradeToExecute;
}

void	Form::beSigned( Bureaucrat const & bureaucrat ) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return (BOLD_RED "[Form] " RED"Bureaucrat's grade is too high" RESET);
}

const char	*Form::GradeTooLowException::what() const throw() {
	return (BOLD_RED "[Form] " RED"Bureaucrat's grade is too low" RESET);
}

std::ostream	&operator<<( std::ostream & o, Form const & rhs ) {
	o << BOLD_GREEN "[" << typeid(rhs).name() + 1 << "] ";
	o << RESET UNDERLINE_WHITE << rhs.getName() << GREEN" form" RESET << endl;
	o << BOLD_GREEN "Grade to sign: " << RESET << rhs.getGradeToSign() << endl;
	o << BOLD_GREEN "Grade to execute: " << RESET << rhs.getGradeToExecute() << endl;
	o << BOLD_GREEN "Signed: " << RESET << (rhs.getSigned() ? GREEN"Yes" RESET : RED"No" RESET) << endl;
	return o;
}