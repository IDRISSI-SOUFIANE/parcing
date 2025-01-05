#ifndef LIBFT_H
# define LIBFT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

char	*parsing(char **av);

size_t	ft_strlen(char *s);
char	*ft_strcpy(char	*dst, char *s);
char	*ft_strcat(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);

void	*ft_free(char **s, int count);
int     is_space(char c, char sp);
int     ft_count_word(char *str, char sp);
char    *ft_strdup_split(char *str, int *preffix, char sp);
char    **ft_split(char *str, char sp);


int	duplicate_sign(char *s);
int	check_digit(char *s);
long	ft_atoi(char *s);
# endif