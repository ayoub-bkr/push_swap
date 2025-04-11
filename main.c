/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:55:20 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/11 09:55:32 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	if (!*a || !a)
		return ;
	tmp = *a;
	while (tmp)
	{
		(*a) = (*a)->next;
		free(tmp);
		tmp = *a;
	}
}

void	free_strs(char **str)
{
	int	i;

	if (!str || !*str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	error(char **nbs, t_stack **a)
{
	write(2, "Error\n", 6);
	free_strs(nbs);
	free_stack(a);
	exit(1);
}

int	already_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	int		size;	
	t_stack	*a;
	t_stack	*b;

	i = 1;
	a = NULL;
	b = NULL;
	parsing(ac, av, &a);
	size = ft_lstsize(a);
	if (ac >= 2 && !already_sorted(a))
		sorting(a, b, size);
	free_stack(&a);
	free_stack(&b);
}
