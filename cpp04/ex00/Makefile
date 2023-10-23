NAME = Animal
CC = c++ -std=c++98
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp WrongDog.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp WrongDog.hpp

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