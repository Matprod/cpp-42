/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:40:03 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/02 14:13:43 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	string _type;
public:
	WrongCat();
	WrongCat(string name);
	WrongCat(WrongCat const &rhs);
	WrongCat &operator=(WrongCat const &rhs);
	~WrongCat();
	string	getType() const;
	string	getName() const;
	void	makeSound( void ) const;
};