#include <stdlib.h>

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

int ft_atoi(char *str)
{
	int	res;
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
		str++;
	}
	return (res * sign);
}

// #include <stdio.h>
// int main(int ac, char **av)
// {
//     // char *str = av[1];
//     // // char *sub = ft_substr(str, 1, 3);
    
//     // char **tmp = strs;
//     // while (*strs)
//     // {
//     //     printf("%s\n", *strs);
//     //     free(*strs);
//     //     strs++;
//     // }
//     // free(tmp);
	
// 	int i = 0;
// 	char **strs = ft_split(av[1]);
// 	while (strs[i])
// 	{
// 		printf("%d\n", ft_atoi(strs[i++]));
// 	}
// }
