CC = cc

SRC = main.c utils.c linked_lists.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

NAME = push_swap

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ)