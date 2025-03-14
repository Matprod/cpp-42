/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:22:03 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/11 15:48:24 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

typedef std::string string;

void	find_and_replaced(std::ifstream &infile, std::ofstream &outfile, const string &s1, const string &s2)
{
	string line;
	size_t pos;

	while (std::getline(infile, line)) {
		pos = 0;
		string new_line;
		while ((pos = line.find(s1, pos)) != string::npos) {
			new_line += line.substr(0, pos) + s2;
			line = line.substr(pos + s1.length());
			pos = 0;
		}
		new_line += line;
		outfile << new_line << std::endl;
	}
}

int	main(int argc, char **argv) {

	string			filename;
	string			s1;
	string			s2;

	if (argc != 4) {
		std::cerr << "Error: arguments should be" << argv[0] << " <filename> <replaced_word> <new_word>" << std::endl;
		return (1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty()) {
		std::cerr << "Error: the replaced word cannot be empty." << std::endl;
		return (1);
	}
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Can't open the file :" << argv[1] << std::endl;
		return (1);
	}
	string	newname = filename +".replace";
	std::ofstream outfile(newname.c_str());
	if (!outfile) {
		std::cerr << "Error: Can't create output file." << std::endl;
		return (1);
	}
	find_and_replaced(infile, outfile, s1, s2);
	infile.close();
	outfile.close();
	std::cout << "✅ File processed successfully! Output: " << newname << std::endl;
}