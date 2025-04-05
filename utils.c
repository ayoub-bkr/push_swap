#include "push_swap.h"

static int words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
	i++;
	while (str[i])
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
			i++;
		if (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13) || str[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

char *ft_substr(char *str, int start, int len)
{
	int		i;
	char	*m;

	i = 0;
	m = (char *)malloc(sizeof(char) * (len + 1));
	if (!m)
		return (NULL);
	while (i < len)
		m[i++] = str[start++];
	m[i] = '\0';
	return (m);
}

char **ft_split(char *str)
{
	int		i;
	int		len;
	char	**m;

	i = 0;
	m = (char **)malloc(sizeof(char *) * (words(str) + 1));
	if (words(str) == 0)
	{
		free(m);
		return (NULL);
	}
	while (*str)
	{
		len = 0;
		while (*str == ' ')
			str++;
		if (!*str)
			break ;
		while (str[len] && str[len] != ' ')
			len++;
		m[i++] = ft_substr(str, 0, len);
		str += len;
	}
	m[i] = NULL;
	return (m);
}

long	ft_atoi(char *str)
{
	long	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		res *= 10;
		res += *str - 48;
		if (res * sign > 2147483647 || res * sign < -2147483648)
			return (2147483648);
		str++;
	}
	return (res * sign);
}