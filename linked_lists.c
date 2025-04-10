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
