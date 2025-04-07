#include "push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*tmp;
	if (!*a || !a)
		return ;
	tmp = *a;
	while (tmp)
	{
		(*a) = (*a)->next;
		free(tmp);
		tmp = *a;
	}
}
void	free_strs(char **str)
{
	int i;

	if (!str || !*str)
		return ;
	i = 0;
	while(str[i])
		free(str[i++]);
	free(str);
}

int count(t_stack *a)
{
	int i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
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
void	sort_3(t_stack *a)
{
	if (a->data < a->next->data && a->next->data > a->next->next->data)
		rra(&a);
	else if (a->data > a->next->data && a->data > a->next->next->data)
		ra(&a);
	if ((a->next->next->data > a->data && a->data > a->next->data))
		sa(&a);
}
void	sort_4(t_stack *a, t_stack *b)
{
	int i;

	i = find_min(a);
	if (i == 3)
		rra(&a);
	else if (i == 1)
		ra(&a);
	else if (i == 2)
	{
		ra(&a);
		ra(&a);
	}
	pb(&a, &b);
	sort_3(a);
	pa(&a, &b);
}
void	sort_5(t_stack *a, t_stack *b)
{
	int i;

	i = find_min(a);
	if (i == 1)
		ra(&a);
	else if (i == 2)
	{
		ra(&a);
		ra(&a);
	}
	if (i == 3)
	{
		rra(&a);
		rra(&a);
	}
	else if (i == 4)
		rra(&a);
	if (i > 0)
	{
		pb(&a, &b);
		sort_4(a, b);
		pa(&a, &b);
	}
}
void	sorting(t_stack *a, t_stack *b)
{
	if (count(a) == 2)
	{
		if (a->data > a->next->data)
			sa(&a);
	}
	else if (count(a) == 3)
		sort_3(a);
	else if (count(a) == 4)
		sort_4(a, b);
	else if (count(a) == 5)
		sort_5(a, b);
}
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
void	indexing(t_stack *a)
{
	int	array[count(a) + 1];
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		// printf("%d | %d\n", best_position(a, tmp->data), tmp->data);
		array[best_position(a, tmp->data)] = tmp->data;
		tmp = tmp->next;
	}
	int i = 0;
	while (i < 12)
		printf("%d\n", array[i++]);
}
int main(int ac, char **av)
{
	int		i;	
	t_stack	*a;
	t_stack	*b;

	i = 1;
	a = NULL;
	b = NULL;
	parsing(ac, av, &a);
	indexing(a);
	// pb(&a, &b);pb(&a, &b);pb(&a, &b);
	// sa(&a);sb(&b);ss(&a, &b);
	// ra(&a);rb(&b);rr(&a, &b);
	// rra(&a);rrb(&b);rrr(&a, &b);
	// printf("----\n");
	// i = 0;
	// t_stack *tmp = a;
	// while(tmp)
	// {
	// 	printf("%d\n", tmp->data);
	// 	tmp = tmp->next;
	// }
	// printf("----\n");
	// sorting(a, b);
	// printf("----\n");
	// i = 0;
	// tmp = a;
	// while(tmp)
	// {
	// 	printf("%d\n", tmp->data);
	// 	tmp = tmp->next;
	// }
	// i = 0;
	// tmp = b;
	// while(tmp)
	// {
	// 	printf("%d\n", tmp->data);
	// 	tmp = tmp->next;
	// }
	free_stack(&a);
	free_stack(&b);
}
