# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 21:25:24 by Matprod           #+#    #+#              #
#    Updated: 2025/03/13 13:15:21 by Matprod          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addsuffix .cpp, main harl)
OBJS	= $(SRCS:%.cpp=.build/%.o)

NAME	= harl
CC		= c++
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -std=c++98
HEADERS = harl.hpp
INCLUDE = -I ./

flag:=1
.build/%.o : %.cpp $(HEADER)
		@if [ $(flag) = "1" ]; then\
			clear ;\
			printf "\033[1;35m========================================\n";\
			printf "|       🧟 CPP01 EX05 LOADING... 🧟    |\n";\
			printf "========================================\n";\
			printf "|                                      |\n";\
			printf "|                                      |\n\033[A\033[A";\
		fi
		$(eval flag=$(shell echo $$(($(flag)+1))))
		@setterm -cursor off
		@mkdir -p .build
		@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
		@printf "\033[1;32m|\033[32m                                      \033[m\r"
		@printf "\033[32m| Compiling $@... \033[m\r"

$(NAME):$(OBJS)
		@setterm -cursor on
		@printf "\033[K\033[1;32m| CPP01 Ex05 : compiled                |\n\033[m"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@printf "\033[1;32m========================================\n"
		@printf "|       🧟 COMPILATION FINISHED ! 🧟   |\n"
		@printf "========================================\n\033[m"

all: $(NAME)

clean:
			@printf "\033[1;31m========================================\n"
			@printf "|       🪦  CPP01 EX05 CLEANING 🪦       |\n"
			@printf "========================================\n\033[m"
			@printf "\033[K\033[1;31m|\033[1;33m Destroying objects                   \033[1;31m|\n\033[m"
			@$(RM) .build

fclean:	clean
			@printf "\033[K\033[1;31m|\033[1;31m Destroying all                       \033[1;31m|\n\033[m"
			@$(RM) .build $(NAME)
			@printf "\033[1;31m========================================\n\033[m"

re:		fclean all

.PHONY: all clean fclean re 