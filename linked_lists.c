/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:56:48 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/11 09:56:49 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	ft_lstaddback(t_stack **head, int new)
{
	t_stack	*m;

	m = malloc(sizeof(t_stack));
	if (!m)
		return ;
	if (!*head)
		*head = m;
	else
	{
		while ((*head)->next)
			head = &(*head)->next;
		(*head)->next = m;
	}
	m->data = new;
	m->next = NULL;
}
