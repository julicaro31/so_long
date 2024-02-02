/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:01:21 by jcaro             #+#    #+#             */
/*   Updated: 2023/10/14 15:19:49 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_len(unsigned int n)
{
	unsigned int	count;

	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa_aux(char *num, unsigned int t, unsigned int len, int n)
{
	unsigned int	i;

	i = 1;
	while (i < len)
	{
		num[len - i] = t % 10 + '0';
		t /= 10;
		i++;
	}
	if (n < 0)
		num[0] = '-';
	else
		num[0] = t % 10 + '0';
	num[len] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	char			*num;
	unsigned int	len;
	unsigned int	t;

	if (n < 0)
	{
		t = -n;
		len = get_len(t) + 1;
	}
	else
	{
		t = n;
		len = get_len(t);
	}
	num = (char *)malloc(len + 1);
	if (num == NULL)
		return (NULL);
	num = ft_itoa_aux(num, t, len, n);
	return (num);
}
