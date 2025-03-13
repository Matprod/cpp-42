/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:34:27 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/04 19:23:01 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	std::cout << "\033[1;34mCreation of multiple zombies :\033[0;34m" << std::endl;
	Zombie	*zombie = newZombie("Little Zombie");
	Zombie	test;
	std::cout << std::endl << "\033[1;35mThe zombies will talk :\033[0;35m" << std::endl;
	zombie->announce();
	test.announce();
	randomChump("Chump Zombie");
	std::cout << std::endl << "\033[1;30mThe zombies will be destroyed :" << std::endl;
	delete zombie;
}