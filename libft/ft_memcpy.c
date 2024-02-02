/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:26:24 by jcaro             #+#    #+#             */
/*   Updated: 2023/10/14 15:20:43 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_cast;
	char	*src_cast;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest_cast = (char *)dest;
	src_cast = (char *)src;
	while (i < n)
	{
		dest_cast[i] = src_cast[i];
		i++;
	}
	return (dest);
}
