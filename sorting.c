/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:57:14 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/11 09:57:16 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sorted_array(t_stack *a, int size)
{
	int		*sorted;
	t_stack	*tmp;

	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	tmp = a;
	while (tmp)
	{
		sorted[best_position(a, tmp->data)] = tmp->data;
		tmp = tmp->next;
	}
	return (sorted);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	mid;
	int	pos;

	while (*b)
	{
		mid = ft_lstsize(*b) / 2;
		pos = find_max(*b);
		if (pos <= mid)
			while (pos-- > 0)
				rb(b);
		else
			while (pos++ < ft_lstsize(*b))
				rrb(b);
		pa(a, b);
	}
}

void	push_to_b(t_stack **a, t_stack **b, int sorted_min, int sorted_max)
{
	while (1)
	{
		if ((*a)->data <= sorted_min)
		{
			pb(a, b);
			rb(b);
			return ;
		}
		else if (*a && (*a)->data <= sorted_max)
		{
			pb(a, b);
			if ((*b)->next && (*b)->data < (*b)->next->data)
				sb(b);
			return ;
		}
		ra(a);
	}
}

void	sort_big(t_stack **a, t_stack **b, int size, int chunk)
{
	int	min;
	int	max;
	int	*sorted;

	sorted = sorted_array(*a, size);
	min = 0;
	max = chunk;
	while (*a)
	{
		if ((*a)->data <= sorted[min] || (*a)->data <= sorted[max])
		{
			push_to_b(a, b, sorted[min], sorted[max]);
			if (min < max)
				min++;
			if (max < size - 1)
				max++;
		}
		else
			ra(a);
	}
	push_to_a(a, b);
	free(sorted);
}

void	sorting(t_stack *a, t_stack *b, int size)
{
	int	chunk;

	if (size >= 100)
		chunk = size / 12;
	else
		chunk = size / 6;
	if (size == 2)
	{
		if (a->data > a->next->data)
			sa(&a);
	}
	else if (size == 3)
		sort_3(a);
	else if (size < 10)
		sort_small(&a, &b);
	else
		sort_big(&a, &b, size, chunk);
}
