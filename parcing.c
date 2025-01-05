#include "libft.h"

void f()
{
	system("leaks check");
}

char	*parsing(char **av)
{
	char	*result;
	char	*tmp;
	int		i;

	i = 1;
	result = ft_strdup(av[i]);
	while (av [++i])
	{
		tmp = result;
		result = ft_strjoin(result, av[i]);
		free(tmp);
		tmp = NULL;
		if (!result)
			return (free(result), NULL);
	}
	// should free result in int main;
	return (result);
}

int main(int ac, char **av)
{
	atexit(f);
	char	*result;
    char	**res;
	int		i;

	if (ac == 1 || av[1] == NULL)
        return (0);
	if (av[1][0] == '\0')
	{
		write(1, "Error\n", 6);
		return (0);
	}
    result = parsing(av);
	res = ft_split(result, ' ');
	i = 0;
	while (res[i])
	{
		if (!(ft_atoi(res[i])))  // if ft_atoi return by NULL free the result[i] and free result in general
		{
			res = ft_free(res, i);
			break ;
		}
		else
			printf("here -> (%ld)", (ft_atoi(res[i])));
		i++;
	}
	free(res);
	free(result);
    return (0);
}
