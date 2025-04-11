/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:56:25 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/11 09:56:27 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_stack;

//linked_lists.c
int		ft_lstsize(t_stack *a);
void	ft_lstaddback(t_stack **head, int new);

//main.c
void	free_stack(t_stack **a);
void	free_strs(char **str);
void	error(char **nbs, t_stack **a);
int		already_sorted(t_stack *a);

//op_push_rotate.c
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);

//op_swap_rrotate.c
void	sa(t_stack **a);
void	sb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);

//parsing.c
int		check_input(char *str);
int		check_number(char **nbs);
void	check_double(t_stack *a, char **nbs);
void	parsing(int ac, char **av, t_stack **a);

//sorting_utils.c
int		best_position(t_stack *a, int nb);
int		find_max(t_stack *b);
int		find_min(t_stack *a);
void	sort_small(t_stack **a, t_stack **b);
void	sort_3(t_stack *a);

//sorting.c
int		*sorted_array(t_stack *a, int size);
void	push_to_a(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b, int sorted_min, int sorted_max);
void	sort_big(t_stack **a, t_stack **b, int size, int chunk);
void	sorting(t_stack *a, t_stack *b, int size);

//utils.c
int		ft_isdigit(char c);
char	*ft_substr(char *str, int start, int len);
char	**ft_split(char *str);
long	ft_atoi(char *str);

#endif