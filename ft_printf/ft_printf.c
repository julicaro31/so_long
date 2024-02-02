/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:45:35 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/05 10:51:02 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;

	count = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%' && ft_strchr("cspdiuxX%", *(str + 1)))
		{
			count += ft_printf_type(list, str + 1);
			str += 2;
		}
		else
		{
			write(1, str, 1);
			count++;
			str++;
		}
	}
	va_end(list);
	return (count);
}
