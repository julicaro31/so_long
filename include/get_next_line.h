/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:14:45 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/05 10:31:26 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		get_line(int fd, t_list **list);
size_t	get_size_line(t_list **list);
void	add_chars(t_list **line, char *buffer);
char	*list_to_str(t_list **list);
t_list	*ft_lstadd_back(t_list **lst, char content);
t_list	*ft_lstclear(t_list **lst);
ssize_t	line_complete(t_list **line);
void	reduce_lst(t_list **list);

#endif