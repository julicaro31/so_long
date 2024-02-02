/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:51:51 by jcaro             #+#    #+#             */
/*   Updated: 2023/10/14 14:54:31 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(size);
	if (new_str == NULL)
		return (NULL);
	*new_str = '\0';
	ft_strlcat(new_str, s1, size);
	ft_strlcat(new_str, s2, size);
	return (new_str);
}
