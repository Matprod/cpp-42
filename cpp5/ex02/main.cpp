/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:49:04 by Matprod           #+#    #+#             */
/*   Updated: 2025/05/11 19:22:13 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	shrubberyHeader(void) {
	cout << "\033[2J\033[1;1H";
	cout << BOLD_WHITE"╔═══════════════════════════════════════════════════╗" << endl;
    cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
    cout << BOLD_WHITE"║          🌳 SOME TESTS FOR SHRUBBERY 🌳           ║" << endl;
    cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
    cout << BOLD_WHITE"╚═══════════════════════════════════════════════════╝" << endl << endl;
}

void	robotomyHeader(void) {
	cout << "\033[2J\033[1;1H";
	cout << BOLD_WHITE"╔═══════════════════════════════════════════════════╗" << endl;
    cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
    cout << BOLD_WHITE"║          🤖 SOME TESTS FOR ROBOTOMY 🤖            ║" << endl;
    cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
    cout << BOLD_WHITE"╚═══════════════════════════════════════════════════╝" << endl << endl;
}

void	presidentialHeader(void) {
	cout << "\033[2J\033[1;1H";
	cout << BOLD_WHITE"╔═══════════════════════════════════════════════════╗" << endl;
    cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
    cout << BOLD_WHITE"║          👨 SOME TESTS FOR PRESIDENTIAL 👨        ║" << endl;
    cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
    cout << BOLD_WHITE"╚═══════════════════════════════════════════════════╝" << endl << endl;
}

void	shrubberyDemo(void) {
	shrubberyHeader();
	cout << YELLOW << "Creating bureaucrat with name \"Bowser\" and grade 1..." << RESET << endl;
	Bureaucrat	*Bowser = new Bureaucrat("Bowser", 1);
	cout << YELLOW << "Creating a ShrubberyCreationForm with \"forest\" as destination" << RESET << endl;
	ShrubberyCreationForm	*shrubbery = new ShrubberyCreationForm("forest");
	cout << YELLOW << "Let's see if the form is ok..." << RESET << endl << endl;
	cout << *Bowser << endl << endl << *shrubbery << endl;

	cout << GREEN << "Press enter to continue..." << RESET << endl;
	cin.get();
	shrubberyHeader();

	// No signed form
	cout << YELLOW << "Trying to execute \"ShrubberyCreationForm\" without signing it..." << RESET << endl;
	try {
		Bowser->executeForm(*shrubbery);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();

	// No permission to sign
	cout << YELLOW << "Trying to sign \"ShrubberyCreationForm\" with a bureaucrat of grade 150..." << RESET << endl;
	try {
		Bureaucrat	waluigi = Bureaucrat("Waluigi", 150);
		waluigi.signForm(*shrubbery);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();

	// Sign form
	cout << YELLOW << "Bowser tries to sign \"ShrubberyCreationForm\"..." << RESET << endl;
	try {
		Bowser->signForm(*shrubbery);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();

	cout << YELLOW << "Let's see if it worked..." << RESET << endl;
	cout << *shrubbery;
	cin.get();

	cout << YELLOW << "Trying to execute \"ShrubberyCreationForm\" with a bureaucrat of grade 150..." << RESET << endl;
	try {
		Bureaucrat	waluigi = Bureaucrat("Waluigi", 150);
		waluigi.executeForm(*shrubbery);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();

	cout << YELLOW << "Trying to execute \"ShrubberyCreationForm\" with a bureaucrat of grade 1..." << RESET << endl;
	try {
		Bureaucrat	waluigi = Bureaucrat("Waluigi", 1);
		waluigi.executeForm(*shrubbery);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();
	
	cout << YELLOW << "Bowser tries to execute \"ShrubberyCreationForm\"..." << RESET << endl;
	try {
		Bowser->executeForm(*shrubbery);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cout << endl << YELLOW << "To see the result, open \"forest_shrubbery\" file" << endl << RESET;
	delete Bowser;
	delete shrubbery;
	cin.get();
}

void	robotomyDemo(void) {
	robotomyHeader();
	cout << YELLOW << "Creating bureaucrat with name \"Bowser\" and grade 1..." << RESET << endl;
	Bureaucrat	*Bowser = new Bureaucrat("Bowser", 1);
	cout << YELLOW << "Creating a RobotomyRequestForm with \"WALL-E\" as destination" << RESET << endl;
	RobotomyRequestForm	*robotomy = new RobotomyRequestForm("WALL-E");
	cout << YELLOW << "Let's see if the form is ok..." << RESET << endl << endl;
	cout << *Bowser << endl << endl << *robotomy << endl;

	cout << GREEN << "Press enter to continue..." << RESET << endl;
	cin.get();
	robotomyHeader();

	// No signed form
	cout << YELLOW << "Trying to execute \"RobotomyRequestForm\" without signing it..." << RESET << endl;
	try {
		Bowser->executeForm(*robotomy);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();
	// No permission to sign
	cout << YELLOW << "Trying to sign \"RobotomyRequestForm\" with a bureaucrat of grade 150..." << RESET << endl;
	try {
		Bureaucrat	waluigi = Bureaucrat("Waluigi", 150);
		waluigi.signForm(*robotomy);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();

	// Sign form
	cout << YELLOW << "Bowser tries to sign \"RobotomyRequestForm\"..." << RESET << endl;
	try {
		Bowser->signForm(*robotomy);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();

	cout << YELLOW << "Let's see if it worked..." << RESET << endl;
	cout << *robotomy;
	cin.get();

	cout << YELLOW << "Trying to execute \"RobotomyRequestForm\" with a bureaucrat of grade 150..." << RESET << endl;
	try {
		Bureaucrat	waluigi = Bureaucrat("Waluigi", 150);
		waluigi.executeForm(*robotomy);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();
	cout << YELLOW << "Trying to execute \"RobotomyRequestForm\" with a bureaucrat of grade 1..." << RESET << endl;
	try {
		Bureaucrat	waluigi = Bureaucrat("Waluigi", 1);
		waluigi.executeForm(*robotomy);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();
	cout << YELLOW << "Bowser tries to execute \"RobotomyRequestForm\"..." << RESET << endl;
	try {
		Bowser->executeForm(*robotomy);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	delete Bowser;
	delete robotomy;
	std::system("clear");
}

void	presidentialDemo(void) {
	presidentialHeader();
	cout << YELLOW << "Creating bureaucrat with name \"Bowser\" and grade 1..." << RESET << endl;
	Bureaucrat	*Bowser = new Bureaucrat("Bowser", 1);
	cout << YELLOW << "Creating a PresidentialPardonForm with \"Zaphod Beeblebrox\" as destination" << RESET << endl;
	PresidentialPardonForm	*presidential = new PresidentialPardonForm("Zaphod Beeblebrox");
	cout << YELLOW << "Let's see if the form is ok..." << RESET << endl << endl;
	cout << *Bowser << endl << endl << *presidential << endl;

	cout << GREEN << "Press enter to continue..." << RESET << endl;
	cin.get();
	// No signed form
	cout << YELLOW << "Trying to execute \"PresidentialPardonForm\" without signing it..." << RESET << endl;
	try {
		Bowser->executeForm(*presidential);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();

	// No permission to sign
	cout << YELLOW << "Trying to sign \"PresidentialPardonForm\" with a bureaucrat of grade 150..." << RESET << endl;
	try {
		Bureaucrat	waluigi = Bureaucrat("Waluigi", 150);
		waluigi.signForm(*presidential);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();
	// Sign form
	cout << YELLOW << "Bowser tries to sign \"PresidentialPardonForm\"..." << RESET << endl;
	try {
		Bowser->signForm(*presidential);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();

	cout << YELLOW << "Let's see if it worked..." << RESET << endl;
	cout << *presidential;
	cin.get();

	cout << YELLOW << "Trying to execute \"PresidentialPardonForm\" with a bureaucrat of grade 150..." << RESET << endl;
	try {
		Bureaucrat	waluigi = Bureaucrat("Waluigi", 150);
		waluigi.executeForm(*presidential);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();
	cout << YELLOW << "Trying to execute \"PresidentialPardonForm\" with a bureaucrat of grade 1..." << RESET << endl;
	try {
		Bureaucrat	waluigi = Bureaucrat("Waluigi", 1);
		waluigi.executeForm(*presidential);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	cin.get();
	cout << YELLOW << "Bowser tries to execute \"PresidentialPardonForm\"..." << RESET << endl;
	try {
		Bowser->executeForm(*presidential);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	delete Bowser;
	delete presidential;
	std::system("clear");
	cout << YELLOW << "[END OF THE PROGRAM]" << RESET << endl;
}

int	main(void)
{
	shrubberyDemo();
	robotomyDemo();
	presidentialDemo();
	return (0);
}