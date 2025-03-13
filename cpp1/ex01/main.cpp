/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:34:27 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/05 18:04:06 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <limits>
#include "Zombie.hpp"

int	main(int argc, char **argv) {
	const int MAX_ZOMBIES = 581385084;
	char	*endptr;
	long	nb;

	if (argc != 2) {
		std::cerr << "\033[1;31m[ERROR]\033[0m Usage: \033[1;33m./zombie_horde <positive_number>\033[0m" << std::endl;
		return (1);
	}
	nb = std::strtol(argv[1], &endptr, 10);
	if (*endptr != '\0' || nb <= 0 || nb > std::numeric_limits<int>::max()) {
		std::cerr << "\033[1;31m[ERROR]\033[0m Invalid number of zombies (\033[1;33m" << argv[1] << "\033[0m). "
		          << "Please enter a \033[1;32mpositive integer\033[0m." << std::endl;
		return (1);
	}
	if (nb > MAX_ZOMBIES) {
		std::cerr << "\033[1;31m[ERROR]\033[0m Too many zombies requested! Maximum allowed: "
				<< MAX_ZOMBIES << std::endl;
		return (1);
	}
	std::cout << "\033[1;32m[INFO]\033[0m Creating a zombie horde of \033[1;33m" << nb << "\033[0m..." << std::endl;
	Zombie *horde = zombieHorde(nb, "Frankenstein");
	std::cout << "\n\033[1;35m[INFO]\033[0m The zombies are announcing themselves:\033[0m" << std::endl;
	for (int i = 0; i < nb; i++)
		horde[i].announce();		
	std::cout << "\n\033[1;30m[INFO]\033[0m Destroying and freeing the zombie horde...\033[0m" << std::endl;
	delete[] horde;
	return (0);
}
