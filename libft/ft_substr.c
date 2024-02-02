/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:32:54 by jcaro             #+#    #+#             */
/*   Updated: 2023/10/14 14:58:48 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start >= ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	if (len > (ft_strlen(s + start)))
		len = ft_strlen(s + start);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
