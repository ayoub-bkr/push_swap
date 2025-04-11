/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:55:54 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/11 09:55:56 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*lst;

	if (!*b)
		return ;
	lst = *b;
	*b = (*b)->next;
	lst->next = *a;
	*a = lst;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*lst;

	if (!*a)
		return ;
	lst = *a;
	*a = (*a)->next;
	lst->next = *b;
	*b = lst;
	write(1, "pb\n", 3);
}

void	ra(t_stack **a)
{
	int		tmp;
	t_stack	*lst;
	t_stack	*sec;

	lst = *a;
	sec = (*a)->next;
	while (sec)
	{
		tmp = lst->data;
		lst->data = sec->data;
		sec->data = tmp;
		lst = lst->next;
		sec = sec->next;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	int		tmp;
	t_stack	*lst;
	t_stack	*sec;

	if (!(*b) || !(*b)->next)
		return ;
	lst = *b;
	sec = (*b)->next;
	while (sec)
	{
		tmp = lst->data;
		lst->data = sec->data;
		sec->data = tmp;
		lst = lst->next;
		sec = sec->next;
	}
	write(1, "rb\n", 3);
}
