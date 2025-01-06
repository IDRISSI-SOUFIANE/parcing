#include "libft.h"

void f()
{
	system("leaks check");
}
int	ft_check_parcing(char *res )
{

	if (!(ft_atoi(res)))
		return (free(res), 0);
	else
	{
		printf("here -> (%ld)", (ft_atoi(res)));
	}
	free(res);
	return (1);
}

int	ft_argc(int ac, char **av)
{
	int		i;
	int		j;
	char	**result;

	i = 1;
	while (i < ac)
	{
		result = ft_split(av[i], ' ');
		j = 0;
		while (result[j])
		{
			if (!(ft_check_parcing(result[j])))
				return (free(result), 0);
			else
				j++;
		}
		free(result);
		i++;
	}
	// free(result);
	return (1);
}

int main(int ac, char **av)
{
	atexit(f);
	if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
	if(!(ft_argc(ac, av)))
		return (0);
    return (0);
}
