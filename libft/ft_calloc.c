/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:21:45 by jcaro             #+#    #+#             */
/*   Updated: 2023/10/14 15:19:28 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	array = (void *)malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, nmemb * size);
	return (array);
}
