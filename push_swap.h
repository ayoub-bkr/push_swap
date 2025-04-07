#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list {
	int	data;
	struct s_list *next;
} t_stack;

//linked_lists.c
t_stack	*ft_lstnew(int data);
void	ft_lstaddback(t_stack **head, int new);

//main.c
void	free_stack(t_stack **a);
void	free_strs(char **str);
void	error(char **nbs, t_stack **a);

//op_push_rotate.c
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

//op_rrotate.c
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//op_swap.c
void	sa(t_stack **a);
void	sb(t_stack **a);
void	ss(t_stack **a, t_stack **b);

//parsing.c
int		ft_isdigit(char c);
int		check_input(char *str);
int		check_number(char **nbs);
void	parsing(int ac, char **av, t_stack **a);

//utils.c
char	**ft_split(char *str);
char	*ft_substr(char *str, int start, int len);
long	ft_atoi(char *str);

#endif