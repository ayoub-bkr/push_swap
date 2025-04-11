/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:56:37 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/11 09:56:39 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_position(t_stack *a, int nb)
{
	int		i;
	int		j;
	t_stack	*tmp;

	i = 0;
	j = 0;
	tmp = a;
	while (tmp)
	{
		if (nb > tmp->data)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_max(t_stack *b)
{
	int		i;
	int		j;
	int		nb;
	t_stack	*tmp;

	i = 0;
	j = 0;
	tmp = b;
	nb = b->data;
	while (tmp)
	{
		if (nb < tmp->data)
		{
			nb = tmp->data;
			i = j;
		}
		j++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_min(t_stack *a)
{
	int		i;
	int		j;
	int		nb;
	t_stack	*tmp;

	i = 0;
	j = 0;
	tmp = a;
	nb = a->data;
	while (tmp)
	{
		if (nb > tmp->data)
		{
			nb = tmp->data;
			i = j;
		}
		j++;
		tmp = tmp->next;
	}
	return (i);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	mid;
	int	pos;

	while (ft_lstsize(*a) > 3)
	{
		mid = ft_lstsize(*a) / 2;
		pos = find_min(*a);
		if (pos <= mid)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < ft_lstsize(*a))
				rra(a);
		pb(a, b);
	}
	sort_3(*a);
	while (*b)
		pa(a, b);
}

void	sort_3(t_stack *a)
{
	if (a->data < a->next->data && a->next->data > a->next->next->data)
		rra(&a);
	else if (a->data > a->next->data && a->data > a->next->next->data)
		ra(&a);
	if ((a->next->next->data > a->data && a->data > a->next->data))
		sa(&a);
}
