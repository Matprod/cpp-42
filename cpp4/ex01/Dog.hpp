/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:20:19 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/02 14:17:30 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
private:
	string	_type;
	Brain	*_brain;
public:
	Dog();
	Dog(string name);
	Dog(Dog const &rhs);
	Dog &operator=(Dog const &rhs);
	~Dog();
	string	getType() const;
	string	getName() const;
	void	makeSound( void ) const;
	void	addIdea		( string ) const;
	void	printIdeas	( void ) const;
};


