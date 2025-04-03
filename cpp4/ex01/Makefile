# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axlamber <axlamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 17:38:06 by axlamber          #+#    #+#              #
#    Updated: 2023/03/16 16:37:21 by axlamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addsuffix .cpp, main Animal Cat Dog WrongAnimal WrongCat Brain)
OBJS	= $(SRCS:%.cpp=.build/%.o)

NAME	= animal
CC		= c++
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -std=c++98 

INCLUDE = -I ./
HEADER  = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

flag:=1
.build/%.o : %.cpp $(HEADER)
		@if [ $(flag) = "1" ]; then\
			clear ;\
			printf "\033[1;35m========================================\n";\
			printf "|          CPP04 EX01 LOADING...       |\n";\
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
		@printf "\033[K\033[1;32m| CPP04 Ex01 : compiled                |\n\033[m"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@printf "\033[1;32m========================================\n"
		@printf "|          COMPILATION FINISHED !      |\n"
		@printf "========================================\n\033[m"

all: $(NAME)

clean:
			@printf "\033[1;31m========================================\n"
			@printf "|           CPP04 EX01 CLEANING        |\n"
			@printf "========================================\n\033[m"
			@printf "\033[K\033[1;31m|\033[1;33m Destroying objects                   \033[1;31m|\n\033[m"
			@$(RM) .build

fclean:	clean
			@printf "\033[K\033[1;31m|\033[1;31m Destroying all                       \033[1;31m|\n\033[m"
			@$(RM) .build $(NAME)
			@printf "\033[1;31m========================================\n\033[m"

re:		fclean all

.PHONY: all clean fclean re 
