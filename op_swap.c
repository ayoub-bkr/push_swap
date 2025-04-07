#include "push_swap.h"

void	sa(t_stack **a)
{
	int		tmp;
	t_stack	*sec;

	if (!*a || !(*a)->next)
		return ;
	sec = (*a)->next;
	tmp = (*a)->data;
	(*a)->data = sec->data;
	sec->data = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	int		tmp;
	t_stack	*sec;

	if (!*b || !(*b)->next)
		return ;
	sec = (*b)->next;
	tmp = (*b)->data;
	(*b)->data = sec->data;
	sec->data = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}