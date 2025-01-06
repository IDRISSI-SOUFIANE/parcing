#include "libft.h"

void f()
{
	system("leaks check");
}
int	ft_check_parcing(char *res )
{

	if (!(ft_atoi(res)))
		return ( 0); // if you free res, you will lose the first address, so will lose the rest of the address ()
	else
	{
		printf("here -> (%ld)", (ft_atoi(res)));
		// free(res);
	}
	return (1);
}

int	ft_argc(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**result;

	i = 1;
	while (i < ac)
	{
		result = ft_split(av[i], ' '); // "l 1 2 3" => free 'l' lose the last numbers
		k = 0;
		while (result[k])
			k++;
		j = 0;
		while (result[j])
		{
			if (!(ft_check_parcing(result[j]))) // the probleme is he free 'first char' and lose the reset
			{
				j = 0;
				while (j < k)
				{
					free(result[j]);
					j++;
				}
			}
			else
			{
				j++;
				free(result[j]);
			}
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
