/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:20:19 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 15:54:36 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
private:
	string _type;
public:
	Dog();
	Dog(string name);
	Dog(Dog const &rhs);
	Dog &operator=(Dog const &rhs);
	~Dog();
	void	makeSound( void ) const;
	string	getType() const;
	string	getName() const;
};


