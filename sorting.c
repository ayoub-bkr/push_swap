#include "push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->data < a->next->data && a->next->data > a->next->next->data)
		rra(&a);
	else if (a->data > a->next->data && a->data > a->next->next->data)
		ra(&a);
	if ((a->next->next->data > a->data && a->data > a->next->data))
		sa(&a);
}
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
	return(sorted);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int	mid = ft_lstsize(*b) / 2;
	int	pos;
	while (*b)
	{
		pos = find_max(*b);
		if (pos >= mid)
			while(pos-- > 0)
				ra(b);
		else
			while(pos-- > 0)
				rra(b);
		pa(a, b);
	}
}

void	sort_big(t_stack **a, t_stack **b, int size, int chunk)
{
	int min;
	int	max;
	int	*sorted;

	sorted = sorted_array(*a, size);
	min = 0;
	max = size / chunk;
	while ((*a)->next)
	{
		if ((*a)->data <= sorted[min] || ((*a)->data <= sorted[max]))
		{
			pb(a, b);
			if ((*a)->data <= sorted[min])
				rb(b);
			else if (*b && (*b)-> next && (*b)->data < (*b)->next->data)
				sb(b);
			if (min < max && max < size - 1)
			{
				min++;
				max++;
			}
		}
		else
			ra(a);
	}
	push_to_b(a, b);
	free(sorted);
}

void	sorting(t_stack *a, t_stack *b, int size)
{
	int	chunk;

	if (size <= 100)
		chunk = size / 7;
	else
		chunk = size / 12;
	if (size == 2)
	{
		if (a->data > a->next->data)
			sa(&a);
	}
	else if (size == 3)
		sort_3(a);
	else
		sort_big(&a, &b, size, chunk);
}