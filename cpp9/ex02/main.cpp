/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:27:01 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/13 09:27:04 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main( int argc, char **argv ) {
	if (argc < 2) {
		cout << BOLD_RED"[ERROR] " RED"Wrong number of arguments ! Usage: './PmergeMe <number> <number> ...'" << endl;
		return (EXIT_FAILURE);
	}
	try {
		PmergeMe	mergeMe(argc, argv);
	} catch (std::exception &e) {
		cout << e.what() << endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}