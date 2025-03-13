/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:08:28 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 13:42:53 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

typedef std::string string;
using std::cout;

# define CLAP_HIT_POINT 10
# define CLAP_ENERGY_POINT 10
# define CLAP_ATTACK_DAMAGE 0

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(string _name);
		ClapTrap(ClapTrap const &src);
		ClapTrap &operator=( ClapTrap const & rhs );
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	protected:
		string	_name;
		int		_hit_point;
		int		_energy_point;
		int		_attack_damage;
		int		_max_hit_point;
};


