/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:29:08 by jcaro             #+#    #+#             */
/*   Updated: 2023/10/14 15:21:21 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_aux(unsigned int t, int fd)
{
	if (t < 10)
		ft_putchar_fd(t + '0', fd);
	else
	{
		ft_putnbr_fd_aux(t / 10, fd);
		ft_putchar_fd(t % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	t;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		t = -n;
	}
	else
		t = n;
	ft_putnbr_fd_aux(t, fd);
}
