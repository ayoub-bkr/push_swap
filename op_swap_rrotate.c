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

void	rra(t_stack **a)
{
	int		tmp;
	t_stack	*lst;
	t_stack	*sec;

	lst = *a;
	sec = (*a)->next;
	while(sec->next)
		sec = sec->next;
	while(lst)
	{
		tmp = lst->data;
		lst->data = sec->data;
		sec->data = tmp;
		lst = lst->next;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	int		tmp;
	t_stack	*lst;
	t_stack	*sec;

	lst = *b;
	sec = (*b)->next;
	while(sec->next)
		sec = sec->next;
	while(lst)
	{
		tmp = lst->data;
		lst->data = sec->data;
		sec->data = tmp;
		lst = lst->next;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}