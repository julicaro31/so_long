/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:39:30 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/05 10:50:49 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

int	ft_printf_type(va_list list, const char *str)
{
	unsigned char	c;

	if (*str == 'c')
	{
		c = va_arg(list, int);
		write(1, &c, 1);
		return (1);
	}
	else if (*str == 's')
		return (ft_printf_s(va_arg(list, char *)));
	else if (*str == 'p')
		return (ft_printf_p(va_arg(list, unsigned long int)));
	else if (*str == 'd' || *str == 'i')
		return (ft_printf_di(va_arg(list, int)));
	else if (*str == 'u')
		return (ft_printf_u(va_arg(list, unsigned int)));
	else if (*str == 'x' || *str == 'X')
		return (ft_printf_x(va_arg(list, int), *str));
	else if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
