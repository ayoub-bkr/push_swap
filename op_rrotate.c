#include "push_swap.h"

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