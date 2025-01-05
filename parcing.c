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
	while (av[++i])
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

int	ft_check_parcing(char **res, char *result)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (!(ft_atoi(res[i])))
			return (ft_free(res, (i+1)), free(result), 0);
		else
			printf("here -> (%ld)", (ft_atoi(res[i])));
		i++;
	}
	ft_free(res, i);
	free(result);
	return (1);
}
int main(int ac, char **av)
{
	atexit(f);
	char	*result;
    char	**res;

	if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    result = parsing(av);
	res = ft_split(result, ' ');
	ft_check_parcing(res, result);


    return (0);
}
