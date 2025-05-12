/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:52:06 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/27 16:28:47 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ): _name("default"), _grade(150) {
	cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created by default" RESET << endl;
}

Bureaucrat::Bureaucrat( string name, int grade ): _name(name), _grade(grade) {
	if (_grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created" RESET << endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ): _name(src._name), _grade(src._grade) {
	cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created by copy" RESET << endl;
}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const & rhs ) {
	if (this != &rhs) {
		_grade = rhs._grade;
	}
	cout << BOLD_GREEN "[" << typeid(*this).name() + 2 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << GREEN" created by assignation" RESET << endl;
	return (*this);
}

Bureaucrat::~Bureaucrat( void ) {
	cout << BOLD_RED "[" << typeid(*this).name() + 2 << "] ";
	cout << RESET UNDERLINE_WHITE << _name << RED" destructed" RESET << endl;
}

string	Bureaucrat::getName( void ) const {
	return (_name);
}

int		Bureaucrat::getGrade( void ) const {
	return (_grade);
}

void	Bureaucrat::incrementGrade( void ) {
	if (_grade - 1 < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade -= 1;
}

void	Bureaucrat::decrementGrade( void ) {
	if (_grade + 1 > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return (BOLD_RED "[ERROR] " RED "Bureaucrat's grade is too high" RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return (BOLD_RED "[ERROR] " RED "Bureaucrat's grade is too low" RESET);
}

std::ostream	&operator<<( std::ostream & o, Bureaucrat const & rhs ) {
	o << BOLD_MAGENTA "[" << typeid(rhs).name() + 2 << "] ";
	o << RESET UNDERLINE_WHITE << rhs.getName() << RESET MAGENTA ", bureaucrat grade " << rhs.getGrade() << RESET;
	return (o);
}