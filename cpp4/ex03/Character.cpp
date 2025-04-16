/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:46:16 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/16 17:41:37 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name("Default"), _materiaCount(0) {
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout <<  _name << GREEN" created !" << RESET << endl;
}

Character::Character( string name ) : _name(name), _materiaCount(0) {
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout <<  _name << GREEN" created !" << RESET << endl;
}

Character::Character( Character const &rhs ) {
	*this = rhs;
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout <<  _name << GREEN" created by copy !" << RESET << endl;
}

Character	&Character::operator=( Character const &rhs ) {
	if (this != &rhs) {
		_name = rhs._name;
		_materiaCount = rhs._materiaCount;
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	cout << BOLD_GREEN << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout <<  _name << GREEN" created by assignation !" << RESET << endl;
	return (*this);
}

Character::~Character( void ) {
	for (int i = 0; i < MAX_MATERIA; i++)
		if (_inventory[i])
			delete _inventory[i];
	cout << BOLD_RED << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
	cout <<  _name << RED" destroyed !" << RESET << endl;
}

string const	&Character::getName( void ) const {
	return (_name);
}

void			Character::equip( AMateria *materia ) {
	if (_materiaCount >= MAX_MATERIA) {
		cout << BOLD_RED << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
		cout <<  _name << RED" can't equip more materia !" << RESET << endl;
		return ;
	} else if (!materia) {
		cout << BOLD_RED << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
		cout <<  _name << RED" can't equip NULL materia !" << RESET << endl;
		return ;
	}
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (!_inventory[i]) {
			_inventory[i] = materia;
			_materiaCount++;
			cout << BOLD_YELLOW << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
			cout <<  _name << YELLOW" equiped materia "<< BOLD_MAGENTA << materia->getType()<< RESET<< " at index " << i << RESET << endl;
			return ;
		}
	}
}

void			Character::unequip( int idx ) {
	if (idx < 0 || idx >= MAX_MATERIA) {
		cout << BOLD_RED << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
		cout <<  _name << RED" can't unequip materia at index " << idx << RESET << endl;
	} else if (!_inventory[idx]) {
		cout << BOLD_RED << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
		cout <<  _name << RED" can't unequip NULL materia !" << RESET << endl;
	} else {
		_inventory[idx] = NULL;
		_materiaCount--;
		cout << BOLD_YELLOW << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
		cout <<  _name << YELLOW" unequiped materia at index " << idx << RESET << endl;
	}
}

/*
** Character's use method, use a materia to the Character.
**
** @param int idx
** @param ICharacter &target
** @return void
*/
void			Character::use( int idx, ICharacter &target ) {
	if (idx < 0 || idx >= MAX_MATERIA) {
		cout << BOLD_RED << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
		cout <<  _name << RED" can't use materia at index " << idx << RESET << endl;
	} else if (!_inventory[idx]) {
		cout << BOLD_RED << "[" << typeid(*this).name() + 1 << "] " RESET UNDERLINE_WHITE;
		cout <<  _name << RED" can't use NULL materia !" << RESET << endl;
	} else {
		_inventory[idx]->use(target);
	}
}