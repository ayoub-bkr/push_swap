SRC = linked_lists.c main.c op_push_rotate.c op_rrotate.c op_swap.c parsing.c utils.c

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