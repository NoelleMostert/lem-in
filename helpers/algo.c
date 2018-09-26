/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:13:14 by nmostert          #+#    #+#             */
/*   Updated: 2018/09/26 13:13:18 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	last_room(t_map *f, int i)
{
	if (f->edgetable[i][f->r_no - 1])
	{
		f->pathing[++(f->path_index)] = i;
		f->pathing[++(f->path_index)] = f->r_no - 1;
		return (1);
	}
	return (0);
}

static void	erase_backtrack(t_map *f, int i, int path)
{
	f->edgetable[f->room_index][i] = 0;
	f->edgetable[i][f->room_index] = 0;
	if (path)
	{
		f->pathing[f->path_index] = -1;
		f->path_index--;
	}
}

static int	passage_link(t_map *f, int r_index, int p_index)
{
	while (p_index < f->r_no)
	{
		if (f->edgetable[r_index][++p_index] == 1)
			return (p_index);
	}
	return (0);
}

static int	is_in_path(t_map *f, int r_index)
{
	int i;

	i = -1;
	while (f->pathing[++i] != -1)
	{
		if (f->pathing[i] == r_index)
			return (1);
	}
	return (0);
}

int			algo(t_map *f, int i)
{
	if (f->edgetable[0][f->r_no - 1])
	{
		f->pathing[++(f->path_index)] = f->r_no - 1;
		return (1);
	}
	while ((i = passage_link(f, f->room_index, i)))
	{
		if (last_room(f, i))
			return (1);
		else if (is_in_path(f, i))
			erase_backtrack(f, i, 0);
	}
	if ((f->room_index = passage_link(f, f->room_index, 0)) == 0)
	{
		if (f->path_index == 0 || f->room_index == 0)
			return (0);
		f->room_index = f->pathing[f->path_index - 1];
		erase_backtrack(f, f->pathing[f->path_index], 1);
		if (algo(f, 0))
			return (1);
	}
	f->pathing[++(f->path_index)] = f->room_index;
	if (algo(f, 0))
		return (1);
	return (0);
}
