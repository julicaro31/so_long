/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:35:33 by jcaro             #+#    #+#             */
/*   Updated: 2023/10/15 18:52:48 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printf_type(va_list list, const char *str);
int	ft_printf_s(char *s);
int	ft_printf_p(unsigned long int num);
int	ft_printf_di(int n);
int	ft_printf_u(unsigned int t);
int	ft_printf_x(int num, char c);

#endif