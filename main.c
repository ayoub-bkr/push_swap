#include "push_swap.h"

int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_input(char *str)
{
	while (*str)
	{
		if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
			return (0);
		else if (ft_isdigit(*str) && (*(str + 1) != ' ' && *(str + 1) != '\0' ))
			return (0);
		else if (!(*str == ' ' || ft_isdigit(*str) || *str == '+' || *str == '-'))
			return (0);
		str++;
	}
	return (1);
}

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
	int		j;
	char	**nbs;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	a = NULL;
	b = NULL;
	while (i < ac)
	{
		j = 0;
		if (!check_input(av[i]))
		{
			write(2, "Invalid Input!", 14);
			exit(0);
		}
		nbs = ft_split(av[i]);
		while (nbs[j])
			ft_lstaddback(&a, ft_atoi(nbs[j++]));
		i++;
		free_strs(nbs);
	}
	// op_p(&a, &b);
	op_rr(&a);
	i = 0;
	t_stack *tmp = a;
	while(tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("----\n");
	// op_s(&a);
	i = 0;
	tmp = b;
	while(tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	free_stack(&a);
	free_stack(&b);
}