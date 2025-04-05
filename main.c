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

int main(int ac, char **av)
{
	int		i;	
	t_stack	*a;
	t_stack	*b;

	i = 1;
	a = NULL;
	b = NULL;
	parsing(ac, av, &a);
	// op_p(&a, &b);
	// op_rr(&a);
	// i = 0;
	// t_stack *tmp = a;
	// while(tmp)
	// {
	// 	printf("%d\n", tmp->data);
	// 	tmp = tmp->next;
	// }
	// printf("----\n");
	// // op_s(&a);
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
