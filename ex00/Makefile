NAME = megaphone
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

all :	$(NAME)
		@echo "\n$(GREEN)[ ✔ ] megaphone $(WHITE)"
		@echo "\n▶ TO LAUNCH:\t./megaphone\n"

$(NAME) : 
		$(CC) $(FLAGS) megaphone.cpp -o $(NAME)

clean :
		@echo "$(YELLOW)\n. . . CLEANING OBJECTS . . .\n$(DEF_COLOR)"
		$(RM) $(NAME)

fclean: clean

re : clean fclean

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