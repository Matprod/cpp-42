/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:22:32 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 14:15:33 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

# define FRAG_HIT_POINT 100
# define FRAG_ENERGY_POINT 100
# define FRAG_ATTACK_DAMAGE 30

class FragTrap : public ClapTrap{
	public:
		FragTrap();
		FragTrap(string _name);
		FragTrap(FragTrap const &src);
		FragTrap &operator=( FragTrap const & rhs );
		~FragTrap();
		void highFivesGuys();
};

