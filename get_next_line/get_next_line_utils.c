/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:17:44 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/05 10:35:39 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

t_list	*ft_lstadd_back(t_list **lst, char content)
{
	t_list	*aux;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	aux = *lst;
	if (aux)
	{
		while (aux -> next)
			aux = aux -> next;
		aux -> next = new;
	}
	else
		*lst = new;
	return (*lst);
}

t_list	*ft_lstclear(t_list **lst)
{
	t_list	*aux;
	t_list	*current;

	current = *lst;
	while (current)
	{
		aux = current -> next;
		free(current);
		current = aux;
	}
	*lst = NULL;
	return (NULL);
}

ssize_t	line_complete(t_list **line)
{
	t_list	*temp;

	temp = *line;
	while (temp)
	{
		if ((temp -> content) == '\n')
			return (1);
		temp = temp -> next;
	}
	return (0);
}

void	reduce_lst(t_list **list)
{
	t_list	*aux;
	t_list	*current;
	char	c;

	current = *list;
	c = '\0';
	while (current && c != '\n')
	{
		c = current -> content;
		aux = current -> next;
		free(current);
		current = aux;
	}
	*list = current;
}
