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
		else if (ft_isdigit(*str) && (*(str + 1) != ' ' && *(str + 1) != '\0' && !ft_isdigit(*(str + 1))))
			return (0);
		else if (!(*str == ' ' || ft_isdigit(*str) || *str == '+' || *str == '-'))
			return (0);
		str++;
	}
	return (1);
}

int	check_number(char **nbs)
{
	int	i;
	// int j;

	i = 0;
	while (nbs[i])
	{
		if (ft_atoi(nbs[i]) > 2147483647 || ft_atoi(nbs[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

void	check_double(t_stack *a, char **nbs)
{
	t_stack	*tmp;
	t_stack	*sec;

	tmp = a;
	sec = a->next;
	while (tmp)
	{
		sec = tmp->next;
		while (sec)
		{
			if (tmp->data == sec->data)
				error(nbs, &a);
			sec = sec->next;
		}
		tmp = tmp->next;
	}
}

void	parsing(int ac, char **av, t_stack **a)
{
	int		i;
	int		j;
	char	**nbs;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		nbs = ft_split(av[i]);
		if (nbs && check_number(nbs) && check_input(av[i]))
		{
			while (nbs[j])
				ft_lstaddback(&(*a), ft_atoi(nbs[j++]));
		}
		else
			error(nbs, a);
		check_double(*a, nbs);
		i++;
		free_strs(nbs);
	}
}
