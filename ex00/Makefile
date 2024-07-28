NAME = rush-02

CC = cc

FLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes

MAIN_FILE = main.c

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -I $(INCLUDES_DIR) $(MAIN_FILE) **/*.c -o $(NAME)

fclean:
	rm -f $(NAME)
