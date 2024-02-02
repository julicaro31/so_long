/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:29:46 by jcaro             #+#    #+#             */
/*   Updated: 2023/10/14 15:20:21 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, const char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	trim_len(const char *s1, const char *set)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (is_set(set, s1[i]) && s1[i])
	{
		count++;
		i++;
	}
	if (s1[i])
	{
		i = ft_strlen(s1) - 1;
		while (is_set(set, s1[i]))
		{
			count++;
			i--;
		}
	}
	return (ft_strlen(s1) - count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	len;

	len = trim_len(s1, set);
	trim = (char *)malloc(len + 1);
	if (trim == NULL)
		return (NULL);
	while (is_set(set, *s1) && *s1)
		s1++;
	i = 0;
	while (i < len)
	{
		trim[i] = *s1;
		i++;
		s1++;
	}
	trim[len] = '\0';
	return (trim);
}
