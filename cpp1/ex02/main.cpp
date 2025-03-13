/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:11:58 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/09 20:04:45 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "iomanip"
#include "cstdlib"
#include <string>

typedef	std::string string;

int main (void) {
	string str;
	string *stringPTR;
	string &stringREF = str;

	stringPTR = &str;
	str = "HI THIS IS BRAIN";
	std::cout << "\033[1;34m    String address: \033[0;34m" << &str << std::endl;
	std::cout << "\033[1;35m StringPTR address: \033[0;35m" << stringPTR << std::endl;
	std::cout << "\033[1;32m StringREF address: \033[0;32m" << &stringREF << std::endl << std::endl;
	std::cout << "\033[1;34m   String value: \033[0;34m" << str << std::endl;
	std::cout << "\033[1;35mStringPTR value: \033[0;35m" << *stringPTR << std::endl;
	std::cout << "\033[1;32mStringREF value: \033[0;32m" << stringREF << std::endl;

}
