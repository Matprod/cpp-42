/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:30:42 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/04 19:39:27 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "iostream"
#include "iomanip"
#include "cstdlib"
#include <string>

typedef	std::string string;

class	Zombie {
	public:
		void announce( void );
		Zombie(std::string name);
		Zombie();
		~Zombie();
	private:
		string	_name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif