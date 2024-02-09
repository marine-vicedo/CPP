NAME = PmergeMe
CC = c++ -std=c++98
FLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = PmergeMe.hpp

all :	$(NAME)
	@echo "\n$(GREEN)[ ✔ ] $(NAME)$(DEF_COLOR)"
	@echo "\n▶ TO LAUNCH:\t./$(NAME)\n"

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(YELLOW)\n. . . COMPILING . . .\n$(DEF_COLOR)"

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)\n. . . CLEANING OBJECTS . . .\n$(DEF_COLOR)"
	$(RM) $(OBJ)

fclean: clean
	@echo "$(YELLOW)\n. . . CLEANING EXECUTABLE . . .\n$(DEF_COLOR)"
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re

#Colors
DEF_COLOR = \033[0;39m
GREEN = \033[1;92m
YELLOW = \033[0;93m