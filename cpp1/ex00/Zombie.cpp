/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:33:27 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/04 19:40:34 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
	std::cout << _name << " created" << std::endl;
}

Zombie::Zombie() : _name("Unknown  zombie") {
	std::cout << _name << " created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "\033[0;30m" << _name << " destroyed ! 🪦\033[0m" << std::endl;
}

void	Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ... 🧟" << std::endl;
}