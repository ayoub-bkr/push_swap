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
	while (*a)
	{
		mid = ft_lstsize(*a) / 2;
		pos = find_min(*a);
		if (pos <= mid)
			while(pos-- > 0)
				ra(a);
		else
			while(pos++ < ft_lstsize(*a))
				rra(a);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}
