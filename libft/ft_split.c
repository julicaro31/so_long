/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:24:49 by juliacaro         #+#    #+#             */
/*   Updated: 2023/10/14 15:21:33 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_len(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	memory_check(char **split, char *str, int j)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		while (i < j)
		{
			free(split[i]);
			i++;
		}
		return (0);
	}
	return (1);
}

static char	**ft_split_aux(char **split, char const *s, char c, int j)
{
	int			i;
	char		*str;

	while (*s)
	{
		i = 0;
		while (*s && *s != c)
		{
			i++;
			s++;
		}
		if (i != 0)
		{
			str = (char *)malloc(i + 1);
			if (!memory_check(split, str, j))
				return (NULL);
			ft_strlcpy(str, s - i, i + 1);
			split[j] = str;
			j++;
		}
		if (*s)
			s++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**split;

	split = (char **)malloc(sizeof(char *) * (split_len(s, c) + 1));
	if (split == NULL)
		return (NULL);
	j = 0;
	if (!ft_split_aux(split, s, c, j))
	{
		free(split);
		return (NULL);
	}
	return (split);
}
