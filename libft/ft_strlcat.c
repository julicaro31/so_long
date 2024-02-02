/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:14:36 by jcaro             #+#    #+#             */
/*   Updated: 2023/10/14 14:54:40 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;

	len_dest = ft_strlen(dest);
	if (size == 0 || size <= len_dest)
		return (ft_strlen(src) + size);
	i = 0;
	while (src[i] && i < size - len_dest - 1)
	{
		dest[i + len_dest] = src[i];
		i++;
	}
	dest[i + len_dest] = '\0';
	return (len_dest + ft_strlen(src));
}
