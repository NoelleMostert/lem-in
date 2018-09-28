/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:14:54 by nmostert          #+#    #+#             */
/*   Updated: 2018/09/27 13:36:30 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	links(t_map *f, char *line)
{
	char *l2;

	l2 = strdup(line);
	if (f->begun == 2)
		f->begun = 3;
	if (f->begun != 3)
		leaveandfree(f, 1);
	f->e_list = joiner(f->e_list, l2, 0);
	free(l2);
}
