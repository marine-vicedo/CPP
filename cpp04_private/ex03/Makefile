NAME = Materia
CC = c++ -std=c++98
FLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp

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