/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:22:03 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/03 15:32:39 by mvoisin          ###   ########.fr       */
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
	bool last_line_empty = false;
	infile.seekg(0, std::ios::end);
	std::streampos fileSize = infile.tellg();
	if (fileSize > 0) {
		infile.seekg(fileSize - static_cast<std::streamoff>(1));
		char lastChar;
		infile.get(lastChar);			
		if (lastChar != '\n') {
			last_line_empty = true;
		}
	}
	infile.seekg(0, std::ios::beg);
	while (std::getline(infile, line)) {
		pos = 0;
		string new_line;
		while ((pos = line.find(s1, pos)) != string::npos) {
			new_line += line.substr(0, pos) + s2;
			line = line.substr(pos + s1.length());
			pos = 0;
		}
		new_line += line;
		if (last_line_empty == false)
			outfile << new_line << std::endl;
		else
			outfile << new_line;
	}
}

int	main(int argc, char **argv) {

	string			filename;
	string			s1;
	string			s2;

	if (argc != 4) {
		std::cerr << "Error: arguments should be " << argv[0] << " <filename> <replaced_word> <new_word>" << std::endl;
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

/* #NORMAL
BLACK='\033[0;30m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'
#BOLD
BLACK_BOLD='\033[1;30m'
RED_BOLD='\033[1;31m'
GREEN_BOLD='\033[1;32m'
YELLOW_BOLD='\033[1;33m'
BLUE_BOLD='\033[1;34m'
MAGENTA_BOLD='\033[1;35m'
CYAN_BOLD='\033[1;36m'
WHITE_BOLD='\033[1;37m'

RESET='\033[0m'

exec_test() {
	name=$1
	infile=$2
	old_word=$3
	new_word=$4

	echo $MAGENTA_BOLD"$name: $RESET"
	./replace $2 $3 $4
	if diff "$2.replace" "$2_result" > /dev/null; then
		echo $GREEN"OK"$RESET
	else
		echo $RED"KO"$RESET
	fi
}

clear
echo $BLUE_BOLD"CPP01 ex04 testeur"

echo  $GREEN_BOLD"Compiling the Makefile...\n"
make > /dev/null

exec_test "alphabet_test" "tests/alphabet" "a" "z"
exec_test "alphabet_no_nl_test" "tests/alphabet_no_nl" "z" "a"
exec_test "no_result test" "tests/no_result" "norminet" "42"

#echo ""
#echo $RED_BOLD"Cleaning the code the Makefile and removing test files..." $RESET
make fclean > /dev/null */
//#rm ./tests/*.replace 