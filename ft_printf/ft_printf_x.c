/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliacaro <juliacaro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:42:54 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/07 13:13:46 by juliacaro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

static int	ft_printf_x_aux(unsigned int num, char c)
{
	int	count;

	if (num < 16)
	{
		count = 1;
		if (c == 'x')
			ft_putchar_fd("0123456789abcdef"[num % 16], 1);
		else
			ft_putchar_fd("0123456789ABCDEF"[num % 16], 1);
	}
	else
	{
		count = ft_printf_x_aux(num / 16, c) + 1;
		if (c == 'x')
			ft_putchar_fd("0123456789abcdef"[num % 16], 1);
		else
			ft_putchar_fd("0123456789ABCDEF"[num % 16], 1);
	}
	return (count);
}

int	ft_printf_x(int num, char c)
{
	if (num < 0)
		return (ft_printf_x_aux((unsigned int)num, c));
	else
		return (ft_printf_x_aux(num, c));
}
