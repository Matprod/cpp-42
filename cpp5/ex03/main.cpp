/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:45:22 by Matprod           #+#    #+#             */
/*   Updated: 2025/05/11 19:16:27 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern		*intern = new Intern();
	Bureaucrat	*internB = new Bureaucrat("Intern", 1);
	AForm		*form;
	AForm		*form2;

	std::cout << endl;
	try {
		form = intern->makeForm("shrubbery creation", "forest");
		internB->signForm(*form);
		internB->executeForm(*form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << endl;
	try {
		form2 = intern->makeForm("wrong form", "Bender");
		internB->signForm(*form2);
		internB->executeForm(*form2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << endl;
	delete form;
	delete intern;
	delete internB;
	return (0);
}