#include "push_swap.h"

t_stack *ft_lstnew(int data)
{
	t_stack *m;

	m = (t_stack *)malloc(sizeof(t_stack));
	m->data = data;
	m->next = NULL;
	return (m);
}

void	ft_lstaddback(t_stack **head, int new)
{
	t_stack *m;
	m = malloc(sizeof(t_stack));
	if (!m)
		return ;
	if (!*head)
		*head = m;
	else
	{
		while((*head)->next)
			head = &(*head)->next;
		(*head)->next = m;
	}
	m->data = new;
	m->next = NULL;
}