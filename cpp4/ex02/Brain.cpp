/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:43:25 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/28 13:43:40 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain( void ) {
	_ideas = new string[100];
	cout << BOLD_GREEN"[Brain] 🧠 " GREEN << "default constructor !" << endl;
}

Brain::Brain( Brain const &rhs ) {
	*this = rhs;
	cout << BOLD_GREEN"[Brain] 🧠 " GREEN << "created by copy" << endl;
}

Brain	&Brain::operator=( Brain const & rhs ) {
	if (this != &rhs)
	{
		_ideas = new string[100];
		for (int i = 0; i < 100; i++)
			_ideas[i] = rhs._ideas[i];
	}
	cout << BOLD_GREEN"[Brain] 🧠 " GREEN << "created by assignation " << endl;
	return (*this);
}

Brain::~Brain( void ) {
	delete [] _ideas;
	cout << BOLD_RED"[Brain] 🧠 " RED << "destroyed !" RESET << endl;
}

void	Brain::addIdea(string idea) {
	if (idea == "")
	{
		cout << BOLD_RED"[Brain] 🧠 " RED << "idea is empty !" RESET << endl;
		return ;
	}
	else if (_ideas[99] != "")
	{
		cout << BOLD_RED"[Brain] 🧠 " RED << "the brain is full !" RESET << endl;
		return ;
	}
	for (int i = 0; i < 100; i++)
	{
		if (_ideas[i] == "")
		{
			_ideas[i] = idea;
			cout << BOLD_YELLOW"[Brain] 🧠 " YELLOW << "idea " << idea << " added at the index "<< i << endl;
			return ;
		}
	}
}

void	Brain::printIdeas( void ) {
	if (_ideas[0] == "")
	{
		cout << BOLD_RED"[Brain] 🧠 " RED << "the brain is empty !" RESET << endl;
		return ;
	}

	cout << endl << BOLD_MAGENTA"[Brain] 🧠 " MAGENTA << "ideas :" << endl;
	for (int i = 0; i < 100; i++)
		if (_ideas[i] != "")
			cout << BOLD_MAGENTA"[Brain] 🧠 " MAGENTA << "idea[" << i << "]: " << _ideas[i] << endl;
}
