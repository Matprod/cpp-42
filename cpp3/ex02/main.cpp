/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:26:20 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 14:12:22 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	FragTrap	alan("Alan");

	alan.attack("Alan");
	alan.attack("Alan");
	alan.attack("Alan");
	alan.takeDamage(2);
	alan.beRepaired(2);
	alan.takeDamage(6);
	alan.takeDamage(6);
	alan.beRepaired(10);
	alan.takeDamage(6);
	alan.beRepaired(10);
	alan.attack("Alan");
	alan.beRepaired(10);
	alan.attack("Alan");
	alan.attack("Alan");
	alan.attack("Alan");
	alan.attack("Alan");
	alan.attack("Alan");
	alan.highFivesGuys();
	alan.beRepaired(1);

	return (0);
}