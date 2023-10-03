NAME = bsp
CC = c++ -std=c++98
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Fixed.hpp Point.hpp

all :	$(NAME)
		@echo "\n$(GREEN)[ ✔ ] $(NAME) $(WHITE)"
		@echo "\n▶ TO LAUNCH:\t./$(NAME)\n"

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)
		@echo "$(YELLOW)\n. . . COMPILING . . .\n$(DEF_COLOR)"
		
%.o: %.cpp
		@$(CC) $(FLAGS) -c $< -o $@

clean :
		@echo "$(YELLOW)\n. . . CLEANING OBJECTS . . .\n$(DEF_COLOR)"
		$(RM) $(OBJ)

fclean:	clean
		@echo "$(YELLOW)\n. . . CLEANING EXECUTABLE . . .\n$(DEF_COLOR)"
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re header

#Colors
DEF_COLOR = \033[0;39m
GREY = \033[0;90m
RED = \033[0;91m
GREEN = \033[1;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[1;95m
CYAN = \033[0;96m
WHITE = \033[0;97m