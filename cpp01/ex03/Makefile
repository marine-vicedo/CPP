NAME = WeaponWar
CC = c++
FLAGS = -Wall -Wextra -Werror --std=c++98
RM = rm -f

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ =$(SRC:.cpp=.o)
HEADER = Weapon.hpp HumanA.hpp HumanB.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re

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
