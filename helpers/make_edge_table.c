/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_edge_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:14:23 by nmostert          #+#    #+#             */
/*   Updated: 2018/09/26 13:14:25 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	validate_link(t_map *f, char *link)
{
	char **l;

	l = ft_strsplit(link, '-');
	if (l[2] != NULL)
		free_array(l, f, 1);
	free_array(l, f, 0);
}

void		make_edge_table(t_map *f)
{
	int		i;
	int		ra;
	int		rb;
	char	**l;
	char	**links;

	i = -1;
	links = ft_strsplit(f->e_list, '\n');
	while (links[++i])
	{
		if (links[i][0] == '#')
			continue ;
		validate_link(f, links[i]);
		l = ft_strsplit(links[i], '-');
		if ((ra = room_index(f, l[0], 1)) >= f->r_no ||
			(rb = room_index(f, l[1], 1)) >= f->r_no)
		{
			free_array(l, f, 0);
			free_array(links, f, 1);
		}
		(rb) ? (f->edgetable[ra][rb] = 1) : 0;
		(ra) ? (f->edgetable[rb][ra] = 1) : 0;
		free_array(l, f, 0);
	}
	free_array(links, f, 0);
}
