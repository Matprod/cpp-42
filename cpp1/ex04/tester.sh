# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 15:58:16 by rukkyaa           #+#    #+#              #
#    Updated: 2025/04/03 14:44:54 by mvoisin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

################################################################
#   /$$$$$$   /$$$$$$  /$$        /$$$$$$  /$$$$$$$   /$$$$$$  #
#  /$$__  $$ /$$__  $$| $$       /$$__  $$| $$__  $$ /$$__  $$ #
# | $$  \__/| $$  \ $$| $$      | $$  \ $$| $$  \ $$| $$  \__/ #
# | $$      | $$  | $$| $$      | $$  | $$| $$$$$$$/|  $$$$$$  #
# | $$      | $$  | $$| $$      | $$  | $$| $$__  $$ \____  $$ #
# | $$    $$| $$  | $$| $$      | $$  | $$| $$  \ $$ /$$  \ $$ #
# |  $$$$$$/|  $$$$$$/| $$$$$$$$|  $$$$$$/| $$  | $$|  $$$$$$/ #
#  \______/  \______/ |________/ \______/ |__/  |__/ \______/  #
################################################################

#NORMAL
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
make fclean > /dev/null
#rm ./tests/*.replace
