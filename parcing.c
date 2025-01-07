#include "libft.h"

void f()
{
	system("leaks check");
}
int	ft_check_parcing(char **res)
{
	int	i;
	int	j;

	if (res[0] == NULL)
		return (free(res), write(1, "!!Error\n",6), 0);
	j = 0;
	while (res[j])
		j++;
	i = 0;

	while (res[i])
	{
		if (!(ft_atoi(res[i])))
			return (ft_free(res, (j)), 0);
		else
			printf("(%ld) -> ", ft_atoi(res[i]));
		i++;
	}
	ft_free(res, j);
	return (1);
}

int	ft_check_argv(int ac, char **av)
{
	int		i;
	char	**result;

	i = 1;
	while (i < ac)
	{
		result = ft_split(av[i], ' ');
		if (!(ft_check_parcing(result)))
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	// atexit(f);
	if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
	if(!(ft_check_argv(ac, av)))
	{
		printf("I am heren\n");
		return (0);
	}
    return (0);
}




// int	ft_argc(int ac, char *av)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	char	**result;

// 	i = 1; // 1 < 4
// 	while (i < ac)
// 	{
// 		result = ft_split(av[i], ' '); // "l 1 2 3" => free 'l' lose the last numbers
// 		ft_check_parcing(result);
// 		i++;
// 	}
// 	// free(result);
// 	return (1);
// }

	// int		i;
	// int		j;
	// int		k;
	// char	**result;

	// i = 1;
	// while (i < ac)
	// {
	// 	result = ft_split(av[i], ' '); // "l 1 2 3" => free 'l' lose the last numbers
	// 	k = 0;
	// 	while (result[k])
	// 		k++;
	// 	j = 0;
	// 	while (result[j])
	// 	{
	// 		if (!(ft_check_parcing(result[j]))) // the probleme is he free 'first char' and lose the reset
	// 		{
	// 			j = 0;
	// 			while (j < k)
	// 			{
	// 				free(result[j]);
	// 				j++;
	// 			}
	// 		}
	// 		else
	// 		{
	// 			j++;
	// 			free(result[j]);
	// 		}
	// 	}
	// 	free(result);
	// 	i++;
	// }
	// // free(result);
	// return (1);