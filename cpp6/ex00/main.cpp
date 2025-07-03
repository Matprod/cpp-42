/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:48:43 by mvoisin           #+#    #+#             */
/*   Updated: 2025/05/16 15:26:53 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.hpp"
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		cout << BOLD_RED "[ERROR] " RESET RED "Invalid number of arguments" << endl;
		cout << "Usage: ./convert [string]" RESET << endl;
		return (EXIT_FAILURE);
	}
	converter(argv[1]);
	return (EXIT_SUCCESS);
}