/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:54:33 by nmostert          #+#    #+#             */
/*   Updated: 2018/09/27 13:54:36 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "get_next_line.h"
# include <limits.h>
# include <stdio.h>

typedef struct	s_map
{
	char		**rooms;
	char		*r_list;
	char		*a_list;
	char		*e_list;
	int			r_no;
	int			a_no;
	int			begun;
	int			room_index;
	int			path_index;
	int			*pathing;
	int			**edgetable;
	int			valid[2];
	int			fd;
	int			initialise;
}				t_map;

void			ant_counter(t_map *m, char *line);
void			rooms(t_map *m, char *line);
void			links(t_map *m, char *line);

void			room_adding(t_map *m);
void			make_edge_table(t_map *m);
int				algo(t_map *m, int i);

char			*joiner(char *s1, char *s2, int clean);
void			free_array(char **array, t_map *m, int error);
int				room_index(t_map *m, char *room_name, int start);

void			result(t_map *m);
void			matrix_output(t_map *m);
void			leaveandfree(t_map *m, int error);

#endif
