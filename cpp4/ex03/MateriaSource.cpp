/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:04:57 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/16 17:38:12 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _count(0) {
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 2 << "] " RESET UNDERLINE_WHITE;
	cout <<  "MateriaSource created !" << RESET << endl;
	for (int i = 0; i < MAX_MATERIA; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource const &rhs ) {
	*this = rhs;
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout <<  "MateriaSource created by copy !" << RESET << endl;
}

MateriaSource	&MateriaSource::operator=( MateriaSource const &rhs ) {
	if (this != &rhs) {
		for (int i = 0; i < MAX_MATERIA; i++)
			_materia[i] = rhs._materia[i];
		_count = rhs._count;
	}
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 2 << "] " RESET UNDERLINE_WHITE;
	cout <<  "MateriaSource assignation operator called !" << RESET << endl;
	return (*this);
}

MateriaSource::~MateriaSource( void ) {
	cout << BOLD_RED << "[" << typeid(*this).name() + 2 << "] " RESET UNDERLINE_WHITE;
	cout <<  "MateriaSource destroyed !" << RESET << endl;
	for (int i = 0; i < MAX_MATERIA; i++)
		if (_materia[i])
			delete _materia[i];
}

void	MateriaSource::learnMateria( AMateria *materia ) {
	if (_count >= MAX_MATERIA) {
		cout << BOLD_RED << "MateriaSource is full !" << RESET << endl;
		return ;
	} else if (!materia) {
		cout << BOLD_RED << "MateriaSource can't learn NULL !" << RESET << endl;
		return ;
	}
	if (_count < MAX_MATERIA && materia) {
		_materia[_count] = materia;
		_count++;
	}
}

AMateria	*MateriaSource::createMateria( string const &type ) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (_materia[i] && _materia[i]->getType() == type)
			return (_materia[i]->clone());
	}
	cout << BOLD_RED << "MateriaSource can't create " << type << " !" << RESET << endl;
	return (NULL);
}