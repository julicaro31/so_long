/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:18:50 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/05 10:50:41 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_printf_p(unsigned long int num)
{
	int	count;

	if (num == 0)
	{
		count = 5;
		ft_putstr_fd("(nil)", 1);
	}
	else if (num > 0 && num < 16)
	{
		count = 3;
		ft_putstr_fd("0x", 1);
		ft_putchar_fd("0123456789abcdef"[num % 16], 1);
	}
	else
	{
		count = ft_printf_p(num / 16) + 1;
		ft_putchar_fd("0123456789abcdef"[num % 16], 1);
	}
	return (count);
}
