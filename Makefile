SRC = main.c utils.c linked_lists.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

$(NAME): $(OBJ)
	cc -Wall -Werror -Wextra $(OBJ) -o $(NAME)

all: $(NAME)

%.o: %.c
	cc -Wall -Werror -Wextra -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ)