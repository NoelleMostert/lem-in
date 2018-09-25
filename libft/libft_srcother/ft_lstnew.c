/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:20:04 by ashulha           #+#    #+#             */
/*   Updated: 2018/09/25 12:09:43 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node_new;

	node_new = (t_list*)malloc(sizeof(t_list));
	if (node_new == NULL)
		return (NULL);
	if (content == NULL)
	{
		node_new->content = NULL;
		node_new->content_size = 0;
	}
	else
	{
		node_new->content = malloc(content_size);
		if (node_new->content == NULL)
			return (NULL);
		ft_memcpy(node_new->content, content, content_size);
		node_new->content_size = content_size;
	}
	node_new->next = NULL;
	return (node_new);
}
