/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:26:20 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 11:11:12 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
	ClapTrap me("me");
	ScavTrap faker("Faker le goat");
	cout << std::endl;

	me.attack("Faker le goat");
	faker.takeDamage(40);
	faker.guardGate();
	faker.beRepaired(20);
	faker.attack("me");
	cout << std::endl;
}