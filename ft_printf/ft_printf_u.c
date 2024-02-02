/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:50:14 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/05 10:50:53 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_printf_u(unsigned int t)
{
	int	count;

	if (t < 10)
	{
		ft_putchar_fd(t + '0', 1);
		count = 1;
	}
	else
	{
		count = ft_printf_u(t / 10) + 1;
		ft_putchar_fd(t % 10 + '0', 1);
	}
	return (count);
}
