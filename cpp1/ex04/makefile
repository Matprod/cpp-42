# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 14:22:07 by Matprod           #+#    #+#              #
#    Updated: 2025/04/03 15:31:00 by mvoisin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addsuffix .cpp, main)
OBJS	= $(SRCS:%.cpp=.build/%.o)

NAME	= replace
CC		= c++
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -std=c++98
HEADERS =
INCLUDE = -I ./

flag:=1
.build/%.o : %.cpp
		@if [ $(flag) = "1" ]; then\
			clear ;\
			printf "\033[1;35m========================================\n";\
			printf "|       🧟 CPP01 EX04 LOADING... 🧟    |\n";\
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
		@printf "\033[K\033[1;32m| CPP01 Ex04 : compiled                |\n\033[m"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@printf "\033[1;32m========================================\n"
		@printf "|       🧟 COMPILATION FINISHED ! 🧟   |\n"
		@printf "========================================\n\033[m"

all: $(NAME)

clean:
			@printf "\033[1;31m========================================\n"
			@printf "|       🪦  CPP01 EX04 CLEANING 🪦       |\n"
			@printf "========================================\n\033[m"
			@printf "\033[K\033[1;31m|\033[1;33m Destroying objects                   \033[1;31m|\n\033[m"
			@$(RM) .build

fclean:	clean
			@printf "\033[K\033[1;31m|\033[1;31m Destroying all                       \033[1;31m|\n\033[m"
			@$(RM) .build $(NAME)
			@printf "\033[1;31m========================================\n\033[m"

re:		fclean all

