#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list {
	int	data;
	struct s_list *next;
} t_stack;


//utils.c

char	**ft_split(char *str);
char	*ft_substr(char *str, int start, int len);
int		ft_atoi(char *str);
//linked_lists.c

void	ft_lstaddback(t_stack **head, int new);
//main.c

int ft_isdigit(char c);
int	check_input(char *str);
void	freeing(t_stack **a);


#endif