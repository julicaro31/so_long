/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:13:30 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/05 10:50:34 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

static int	ft_printf_di_aux(unsigned int t)
{
	int	count;

	if (t < 10)
	{
		count = 1;
		ft_putchar_fd(t + '0', 1);
	}
	else
	{
		count = ft_printf_di_aux(t / 10) + 1;
		ft_putchar_fd(t % 10 + '0', 1);
	}
	return (count);
}

int	ft_printf_di(int n)
{
	unsigned int	t;
	int				count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		t = -n;
		count++;
	}
	else
		t = n;
	return (ft_printf_di_aux(t) + count);
}
