/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:25:09 by nmostert          #+#    #+#             */
/*   Updated: 2018/09/27 15:19:48 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		is_empty(char *s)
{
	int i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

static t_map	*initialise_map_cont(t_map *f)
{
	int i;
	int j;

	i = -1;
	f->initialise = 1;
	f->pathing = (int*)ft_memalloc(sizeof(int) * 1000);
	f->edgetable = (int**)ft_memalloc(sizeof(int*) * f->r_no);
	f->rooms = (char**)ft_memalloc(sizeof(char*) * (f->r_no + 1));
	while (++i < f->r_no)
	{
		f->pathing[i] = -1;
		f->rooms[i] = NULL;
		f->edgetable[i] = (int*)ft_memalloc(sizeof(int) * f->r_no);
		j = -1;
		while (f->edgetable[i][++j])
			f->edgetable[i][j] = 0;
	}
	f->rooms[i] = NULL;
	f->pathing[0] = 0;
	return (f);
}

static void		read_map(t_map *f)
{
	char *line;

	while (get_next_line(f->fd, &line) > 0)
	{
		if (f->a_no == 0)
		{
			ant_counter(f, line);
			free(line);
		}
		else if (ft_strchr(line, '-') || f->begun == 3)
		{
			links(f, line);
			free(line);
		}
		else if ((f->begun == 1 || f->begun == 2) && !is_empty(line))
		{
			rooms(f, line);
			free(line);
		}
		else
			leaveandfree(f, 1);
	}
	line ? free(line) : 0;
	(!f->a_no || !f->e_list[0]) ? leaveandfree(f, 1) : 0;
	f = initialise_map_cont(f);
}

static t_map	*initialise_map(void)
{
	t_map *f;

	f = (t_map*)ft_memalloc(sizeof(t_map));
	f->e_list = ft_strnew(1);
	f->a_list = ft_strnew(1);
	f->r_list = ft_strnew(1);
	f->r_no = 0;
	f->a_no = 0;
	f->begun = 0;
	f->room_index = 0;
	f->path_index = 0;
	f->initialise = 0;
	f->valid[0] = 0;
	f->valid[1] = 0;
	f->rooms = NULL;
	f->edgetable = NULL;
	f->pathing = NULL;
	f->fd = 0;
	return (f);
}

int				main(void)
{
	t_map *f;

	f = initialise_map();
	read_map(f);
	room_adding(f);
	if (!f->valid[0] || !f->valid[1])
		leaveandfree(f, 1);
	make_edge_table(f);
	matrix_output(f);
	if (algo(f, 0))
		result(f);
	else
		leaveandfree(f, 1);
	leaveandfree(f, 0);
}
