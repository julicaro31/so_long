/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:46:08 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/05 10:50:45 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_printf_s(char *s)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
