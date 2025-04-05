#include "push_swap.h"

static void	op_swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	op_s(t_stack **a)
{
	int		tmp;
	t_stack	*sec;

	if (!*a || !(*a)->next)
		return ;
	sec = (*a)->next;
	tmp = (*a)->data;
	(*a)->data = sec->data;
	sec->data = tmp;
}
void	op_p(t_stack **a, t_stack **b)
{
	t_stack	*lst;

	if (!*a)
		return ;
	lst = *a;
	*a = (*a)->next;
	lst->next = *b;
	*b = lst;
}
void	op_r(t_stack **a)
{
	t_stack	*lst;
	t_stack	*sec;

	lst = *a;
	sec = (*a)->next;
	while (sec)
	{
		op_swap(&lst->data, &sec->data);
		lst = lst->next;
		sec = sec->next;
	}
}
void	op_rr(t_stack **a)
{
	t_stack	*lst;
	t_stack	*sec;

	lst = *a;
	sec = (*a)->next;
	while(sec->next)
		sec = sec->next;
	while(lst)
	{
		op_swap(&lst->data, &sec->data);
		lst = lst->next;
	}
}