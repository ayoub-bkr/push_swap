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

void	error(char **nbs, t_stack **a)
{
	write(2, "Error\n", 6);
	free_strs(nbs);
	free_stack(a);
	exit(1);
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

int main(int ac, char **av)
{
	int		i;
	int		size;	
	t_stack	*a;
	t_stack	*b;

	i = 1;
	a = NULL;
	b = NULL;
	parsing(ac, av, &a);
	size = ft_lstsize(a);
	
	// i = 0;
	// t_stack *tmp = a;
	// while(tmp)
	// {
	// 	printf("%d\n", tmp->data);
	// 	tmp = tmp->next;
	// }
	sorting(a, b, size);
	// printf("----\n");
	// i = 0;
	// tmp = a;
	// while(tmp)
	// {
	// 	printf("%d\n", tmp->data);
	// 	tmp = tmp->next;
	// }
	// printf("----\n");
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
