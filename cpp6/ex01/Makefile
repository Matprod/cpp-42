SRCS	= $(addsuffix .cpp, main Data Serializer)
OBJS	= $(SRCS:%.cpp=.build/%.o)

NAME	= convert
CC		= c++
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -std=c++98 

INCLUDE = -I ./
HEADER  = $(addsuffix .hpp, Data Serializer)

flag:=1
.build/%.o : %.cpp $(HEADER)
		@if [ $(flag) = "1" ]; then\
			clear ;\
			printf "\033[1;35m╔══════════════════════════════════════╗\n";\
			printf "║          CPP06 EX01 LOADING...       ║\n";\
			printf "╠══════════════════════════════════════╣\n";\
			printf "║                                      ║\n";\
			printf "║                                      ║\n\033[A\033[A";\
		fi
		$(eval flag=$(shell echo $$(($(flag)+1))))
		@setterm -cursor off
		@mkdir -p .build
		@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
		@printf "\033[1;32m|\033[32m                                      \033[m\r"
		@printf "\033[32m║ Compiling $@... \033[m\r"

$(NAME):$(OBJS)
		@setterm -cursor on
		@printf "\033[K\033[1;32m║ CPP06 Ex01 : compiled                ║\n\033[m"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@printf "\033[1;32m╠══════════════════════════════════════╣\n"
		@printf "║          COMPILATION FINISHED !      ║\n"
		@printf "╚══════════════════════════════════════╝\n\033[m"

all: $(NAME)

help:
	@printf "\033[1;36m╔═══════════════════════════════════════════════════╗\n"
	@printf "║                  CPP06 EX01 HELP                  ║\n"
	@printf "╠═══════════════════════════════════════════════════╣\n"
	@printf "║                      OPTIONS                      ║\n"
	@printf "╠═══════════════════════════════════════════════════╣\n"
	@printf "║                                                   ║\n"
	@printf "║ %-50s║\n" "make all : compile the project"
	@printf "║ %-50s║\n" "make clean : remove .o files"
	@printf "║ %-50s║\n" "make fclean : remove .o and binary"
	@printf "║ %-50s║\n" "make re : fclean + all"
	@printf "║ %-50s║\n" "make help : show this help"
	@printf "║ %-50s║\n" "make debug : compile with debug flags"
	@printf "╚═══════════════════════════════════════════════════╝\n\033[m"

debug: CFLAGS += -D DEBUG
debug: re
		@printf "\n"
		@./$(NAME)

clean:
			@printf "\033[1;31m╔══════════════════════════════════════╗\n"
			@printf "║           CPP06 EX01 CLEANING        ║\n"
			@printf "╠══════════════════════════════════════╣\n\033[m"
			@printf "\033[K\033[1;31m║\033[1;33m Destroying objects                   \033[1;31m║\n\033[m"
			@$(RM) .build
			@printf "\033[1;31m╚══════════════════════════════════════╝\n\033[m"

fclean:
			@printf "\033[1;31m╔══════════════════════════════════════╗\n"
			@printf "║           CPP06 EX01 CLEANING        ║\n"
			@printf "╠══════════════════════════════════════╣\n\033[m"
			@printf "\033[K\033[1;31m║\033[1;33m Destroying objects                   \033[1;31m║\n\033[m"
			@printf "\033[K\033[1;31m║\033[1;31m Destroying binary                    \033[1;31m║\n\033[m"
			@$(RM) .build $(NAME)
			@printf "\033[1;31m╚══════════════════════════════════════╝\n\033[m"

re:		fclean all

.PHONY: all clean fclean re help debug error
