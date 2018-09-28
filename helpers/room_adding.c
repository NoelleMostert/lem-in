/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_adding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:14:31 by nmostert          #+#    #+#             */
/*   Updated: 2018/09/27 14:23:26 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	start_end(t_map *f, char **r, int end)
{
	if (end)
	{
		f->rooms[f->r_no - 1] = ft_strdup(r[0]);
		(f->valid[1])++;
		return ;
	}
	f->rooms[0] = ft_strdup(r[0]);
	(f->valid[0])++;
}

static void	works(t_map *f, char **line, char **r, int end)
{
	if (++(f->valid[end]) > 1)
	{
		free_array(r, f, 0);
		free_array(line, f, 1);
	}
}

static void	valid_check(t_map *f, int i, char **r)
{
	int r_index;

	r_index = room_index(f, r[0], 0);
	if (r_index > 0 && i != r_index)
		leaveandfree(f, 1);
	f->rooms[i] = ft_strdup(r[0]);
}

void		room_adding(t_map *f)
{
	int		i;
	int		j;
	char	**line;
	char	**r;

	i = -1;
	j = 1;
	line = ft_strsplit(f->r_list, '\n');
	while (line[++i] && j < f->r_no)
	{
		r = ft_strsplit(line[i], ' ');
		if (!ft_strcmp("##start", line[i]))
			works(f, line, r, 0);
		else if (!ft_strcmp("##end", line[i]))
			works(f, line, r, 1);
		else if (f->valid[0] == 1 && line[i][0] != '#')
			start_end(f, r, 0);
		else if (f->valid[1] == 1 && line[i][0] != '#')
			start_end(f, r, 1);
		else if (line[i][0] != '#')
			valid_check(f, j++, r);
		free_array(r, f, 0);
	}
	free_array(line, f, 0);
}
