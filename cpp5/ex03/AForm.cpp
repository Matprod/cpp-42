/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:54:30 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/28 13:11:24 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ): _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {
		cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << GREEN" created by default" RESET << endl;
}

AForm::AForm( string name, int gradeToSign, int gradeToExecute ): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToSign < MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (_gradeToSign > MIN_GRADE)
		throw AForm::GradeTooLowException();
	if (_gradeToExecute < MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (_gradeToExecute > MIN_GRADE)
		throw AForm::GradeTooLowException();
	cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created" RESET << endl;
}

AForm::AForm( AForm const & src ): _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
	cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created by copy" RESET << endl;
}

AForm	&AForm::operator=( AForm const & rhs ) {
	if (this != &rhs) {
		_signed = rhs._signed;
	}
		cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
		cout << RESET UNDERLINE_WHITE << _name << GREEN" acreated by assignation" RESET << endl;
	return *this;
}

AForm::~AForm( void ) {
	cout << BOLD_GREEN "[" << typeid(*this).name() + 1 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" destroyed" RESET << endl;
}

string	AForm::getName( void ) const {
	return _name;
}

bool	AForm::getSigned( void ) const {
	return _signed;
}

int		AForm::getGradeToSign( void ) const {
	return _gradeToSign;
}

int		AForm::getGradeToExecute( void ) const {
	return _gradeToExecute;
}

void	AForm::beSigned( Bureaucrat const & bureaucrat ) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return (BOLD_RED "[AForm] " RED"Bureaucrat's grade is too high" RESET);
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return (BOLD_RED "[AForm] " RED"Bureaucrat's grade is too low" RESET);
}

const char	*AForm::NotSignedException::what() const throw() {
	return (BOLD_RED "[Form] " RED"Form is not signed" RESET);
}

const char	*AForm::FileException::what() const throw() {
	return (BOLD_RED "[Form] " RED"Error while opening the file" RESET);
}

void	AForm::execute( Bureaucrat const & executor ) const {
	if (executor.getGrade() > _gradeToExecute)
	{
		throw AForm::GradeTooLowException();
	}
	else if (!_signed)
		throw AForm::NotSignedException();
}

std::ostream	&operator<<( std::ostream & o, AForm const & rhs ) {
	o << BOLD_GREEN "[" << typeid(rhs).name() + 2 << "] ";
	o << RESET UNDERLINE_WHITE << rhs.getName() << GREEN" AForm" RESET << endl;
	o << BOLD_GREEN "Grade to sign: " << RESET << rhs.getGradeToSign() << endl;
	o << BOLD_GREEN "Grade to execute: " << RESET << rhs.getGradeToExecute() << endl;
	o << BOLD_GREEN "Signed: " << RESET << (rhs.getSigned() ? GREEN"Yes" RESET : RED"No" RESET) << endl;
	return o;
}