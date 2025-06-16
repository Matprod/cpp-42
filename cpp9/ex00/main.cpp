/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:25:49 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/13 16:40:40 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int	main( int argc, char **argv ) {
	if (argc != 2) {
		std::cout << "[ERROR] Wrong number of arguments ! Usage: './btc <dataBaseFile>'" << std::endl;
		return (EXIT_FAILURE);
	}
	std::ifstream	inputFile(argv[1]);
	string		line;

	if (inputFile.fail()) {
		std::cout << "[ERROR] File could not be opened !" << std::endl;
		return (EXIT_FAILURE);
	}

	BitcoinExchange	change("data.csv");
	
	getline(inputFile, line);
	while (getline(inputFile, line)) {
		try {
			change.getExchange(line);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}