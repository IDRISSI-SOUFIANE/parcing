#include "libft.h"

size_t	ft_strlen(char *s)
{
    size_t	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}
char	*ft_strcpy(char	*dst, char *s)
{
	int	i;

	if (!s || !dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;	
	}
	dst[i] = '\0';
	return (dst);
}
char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
char	*ft_strdup(char *s)
{
    char	*str;
    int		len_s;

	if (!s)
        return (NULL);
	len_s = ft_strlen(s);
	str = (char *) malloc((len_s + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strcpy(str, s);
	return (str);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *) malloc((len_s1 + len_s2 + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, " ");
	ft_strcat(str, s2);
	str[len_s1 + len_s2 + 1] = '\0';
	return (str);
}
void	*ft_free(char **s, long count)
{
	long	i;

	i = 0;
	while (i < count)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}
int	is_space(char c, char sp)
{
	return (c == sp);
}
int	ft_count_word(char *str, char sp)
{
  int    i;
  int    count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!(is_space(str[i], sp)) && str[i])
		{
			count++;
			while (!(is_space(str[i], sp)) && str[i])
				i++;
		}
		else
		i++;
	}
	return (count);
}
char	*ft_strdup_split(char *str, int *preffix, char sp)
{
	char	*word;
	int		i;
	int		len_word;

	len_word = 0;
	i = *preffix;
	while (str[i] && is_space(str[i], sp))
		i++;
	*preffix = i;
	while (str[i] && !(is_space(str[i], sp)))
	{
		len_word++;
		i++;
	}
	word = (char *)malloc((len_word + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len_word)
		word[i++] = str[(*preffix)++];
	word[len_word] = '\0';
	return (word);
}
char	**ft_split(char *str, char sp)
{
	char	**word_arr;
	int		count_word;
	int		i;
	int		preffix;

	count_word = ft_count_word(str, sp);
	word_arr = (char **)malloc((count_word + 1) * sizeof(char *));
	if (!word_arr)
		return (NULL);
	preffix = 0;
	i = 0;
	while (i < count_word)
	{
		word_arr[i] = ft_strdup_split(str, &preffix, sp);
		if (!word_arr[i])
			return (ft_free(word_arr, i));
		i++;
	}
	word_arr[count_word] = NULL;
	return (word_arr);
}
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
int	duplicate_sign(char *s)
{
	int		i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i + 1] == '-' || s[i + 1] == '+' || s[i + 1] == ' ' || s[i + 1] == '\0')
		{
			write (1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
int	check_digit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!(is_digit(s[i])))
		{
			write (1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
long	ft_atoi(char *s)
{
	int		sign;
	long	result;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	if (!(duplicate_sign(s)))
		return (0);
	if (!(check_digit(s)))
		return (0);
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	result = result * sign;
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	
	return (result);
}
