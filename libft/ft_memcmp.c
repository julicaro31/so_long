/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:45:48 by jcaro             #+#    #+#             */
/*   Updated: 2023/10/14 14:52:51 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	if (n == 0)
		return (0);
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while (i < n && t1[i] == t2[i])
		i++;
	if (i == n)
		i--;
	return (t1[i] - t2[i]);
}
