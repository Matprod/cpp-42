# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 14:22:07 by Matprod           #+#    #+#              #
#    Updated: 2025/03/13 13:15:32 by Matprod          ###   ########.fr        #
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

# ===========================
#       TESTING RULE
# ===========================

TEST_DIR = tests
TEST_EXEC = ./replace
TEST_FILES = file1 file2 file3
TEST_STATUS = 0

# Création des fichiers de test
init:
	mkdir -p $(TEST_DIR)
	echo "This is a simple test file." > $(TEST_DIR)/file1
	echo "Hello world! Hello again!" > $(TEST_DIR)/file2
	echo "The quick brown fox jumps over the lazy dog." > $(TEST_DIR)/file3
	echo "Résultats attendus après transformation :"
	echo "This is a sample test file." > $(TEST_DIR)/file1_expected
	echo "Hi world! Hi again!" > $(TEST_DIR)/file2_expected
	echo "The fast brown fox jumps over the lazy dog." > $(TEST_DIR)/file3_expected

test: $(NAME) init
	@echo "🛠️  Running tests..."
	@TEST_STATUS=0; \
	for file in $(TEST_FILES); do \
		orig="$(TEST_DIR)/$$file"; \
		expected="$(TEST_DIR)/$${file}_expected"; \
		result="$(TEST_DIR)/$$file.replace"; \
		# Remplacements spécifiques pour chaque test \
		if [ "$$file" = "file1" ]; then $(TEST_EXEC) "$$orig" "simple" "sample"; fi; \
		if [ "$$file" = "file2" ]; then $(TEST_EXEC) "$$orig" "Hello" "Hi"; fi; \
		if [ "$$file" = "file3" ]; then $(TEST_EXEC) "$$orig" "quick" "fast"; fi; \
		# Vérification du résultat \
		if diff "$$result" "$$expected" > /dev/null; then \
			echo "✅ $$file: Test Passed!"; \
		else \
			echo "❌ $$file: Test Failed!"; \
			TEST_STATUS=1; \
		fi; \
	done; \
	if [ $$TEST_STATUS -eq 0 ]; then \
		echo "🎉 All tests passed!"; \
	else \
		echo "❌ Some tests failed!"; \
	fi
clean_tests:
		@rm -rf $(TEST_DIR)
		@echo "🧹 Test files cleaned!"

