/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:22:32 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 13:46:51 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

# define SCAV_HIT_POINT 100
# define SCAV_ENERGY_POINT 50
# define SCAV_ATTACK_DAMAGE 20

class ScavTrap : public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(string _name);
		ScavTrap(ScavTrap const &src);
		ScavTrap &operator=( ScavTrap const & rhs );
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
};

