/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:27:07 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 15:54:31 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
private:
	string _type;
public:
	Cat();
	Cat(string name);
	Cat(Cat const &rhs);
	Cat &operator=(Cat const &rhs);
	~Cat();
	string	getType() const;
	string	getName() const;
	void	makeSound( void ) const;
};