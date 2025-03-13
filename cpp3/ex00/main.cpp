/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:26:20 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/13 13:43:52 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
	ClapTrap me("me");
	ClapTrap shaco("Shaco le fou");
	me.attack("Shaco le fou");
	shaco.takeDamage(9);
	me.attack("Shaco le fou");
	shaco.takeDamage(30);
	shaco.attack("me");
	me.takeDamage(10);
	me.beRepaired(20);
	me.attack("Shaco le fou");
	me.attack("Shaco le fou");
	me.attack("Shaco le fou");
	me.attack("Shaco le fou");
	me.attack("Shaco le fou");
	me.attack("Shaco le fou");
	me.attack("Shaco le fou");
	me.attack("Shaco le fou");
	me.attack("Shaco le fou");
	me.beRepaired(20);
	
}