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
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	t_stack *node1, node2, node3;
// 	node1 = malloc(sizeof(t_stack));
// 	node1->next = &node2;
// 	node2.next = &node3;
// 	node3.next = NULL;
	
// 	node1->data = 1;
// 	node2.data = 2;
// 	node3.data = 3;

// 	ft_lstaddback(&node1, 40);
// 	t_stack *tmp;
// 	tmp = node1;
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->data);
// 		tmp = tmp->next;
// 	}
// }