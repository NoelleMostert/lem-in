/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:25:38 by ashulha           #+#    #+#             */
/*   Updated: 2018/09/25 12:09:43 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *node_1;
	t_list *node_2;

	if (!lst)
		return (NULL);
	node_1 = f(lst);
	list = ft_lstnew(node_1->content, node_1->content_size);
	node_2 = list;
	lst = lst->next;
	while (lst != NULL)
	{
		node_1 = f(lst);
		if (!(node_2->next = ft_lstnew(node_1->content, node_1->content_size)))
			return (NULL);
		node_2 = node_2->next;
		lst = lst->next;
	}
	return (list);
}
