/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:26:17 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/13 09:26:20 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int argc, char **argv ) {
	if (argc != 2) {
		cout << BOLD_RED"[ERROR] " RED"Wrong number of arguments ! Usage: './RPN <expr>'" << endl;
		return (EXIT_FAILURE);
	}
	try {
		RPN	rpn(argv[1]);
	} catch (std::exception &e) {
		cout << e.what() << endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
