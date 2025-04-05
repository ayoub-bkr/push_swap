#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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
long	ft_atoi(char *str);

//linked_lists.c
t_stack	*ft_lstnew(int data);
void	ft_lstaddback(t_stack **head, int new);

//operations.c
void	op_s(t_stack **a);
void	op_p(t_stack **a, t_stack **b);
void	op_r(t_stack **a);
void	op_rr(t_stack **a);

//parsing.c
int		ft_isdigit(char c);
int		check_input(char *str);
int		check_number(char **nbs);
void	parsing(int ac, char **av, t_stack **a);

//main.c
void	free_stack(t_stack **a);
void	free_strs(char **str);
void	error(char **nbs, t_stack **a);

#endif