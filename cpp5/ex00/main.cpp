/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:49:04 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/28 14:10:59 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	lowError(void)
{
	Bureaucrat	looser("Looser", 150);
	try
	{
		cout << YELLOW << "Trying to create bureaucrat with grade 151..." << RESET << endl;
		Bureaucrat	big_looser("Big Looser", 151);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	try
	{
		cout << endl << looser << endl;
		cout << YELLOW << "Trying to decrement his grade..." << RESET << endl;
		looser.decrementGrade();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	cout << "Press enter\n";
	cin.get();
	std::system("clear");
}

void	highError(void)
{
	Bureaucrat	winner("Winner", 1);
	try
	{
		cout << YELLOW << "Trying to create bureaucrat with grade 0..." << RESET << endl;
		Bureaucrat	big_winner("Big Winner", 0);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	try
	{
		cout << endl << winner << endl;
		cout << YELLOW << "Trying to increment his grade..." << RESET << endl;
		winner.incrementGrade();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	cout << "Press enter\n";
	cin.get();
	std::system("clear");
}

void	bureaucratDemo(void)
{
	cout << BOLD_WHITE"╔═══════════════════════════════════════════════════╗" << endl;
	cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
	cout << BOLD_WHITE"║          👨 SOME TESTS FOR BUREAUCRATS 👩         ║" << endl;
	cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
	cout << BOLD_WHITE"╚═══════════════════════════════════════════════════╝" << endl << endl;
	cout << YELLOW << "Creating bureaucrat with name \"Mario\" and grade 42..." << RESET << endl;
	Bureaucrat	mario("Mario", 42);
	cout << mario << endl;
	cout << YELLOW << "Trying to increment his grade..." << RESET << endl;
	mario.incrementGrade();
	cout << mario << endl;
	cout << YELLOW << "Trying to decrement his grade..." << RESET << endl;
	mario.decrementGrade();
	cout << mario << endl;
}

int	main(void)
{
	lowError();
	highError();
	bureaucratDemo();
	return (0);
}