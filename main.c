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

void	freeing(t_stack **a)
{
	if (!*a || !a)
		return ;
	while (*a)
	{
		free(*a);
		a++;
	}
	free(a);
}

int main(int ac, char **av)
{
	int		i;
	int		j;
	char	**nbs;
	t_stack	*a;

	i = 1;
	j = 0;
	a = NULL;
	while (i < ac)
	{
		if (!check_input(av[i]))
			write(1, "Error", 5);
		nbs = ft_split(av[i]);
		while (nbs[j])
			ft_lstaddback(&a, ft_atoi(nbs[j++]));
		i++;
	}
	i = 0;
	while (nbs[i])
		free(nbs[i++]);
	free(nbs);
	t_stack *tmp = a;
	while(tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	freeing(&a);
}

