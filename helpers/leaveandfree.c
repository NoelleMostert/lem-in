/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaveandfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:15:33 by nmostert          #+#    #+#             */
/*   Updated: 2018/09/26 13:15:35 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	leaveandfree(t_map *f, int error)
{
	int i;

	free(f->e_list);
	free(f->a_list);
	free(f->r_list);
	if (f->initialise)
	{
		free(f->pathing);
		free_array(f->rooms, f, 0);
		i = -1;
		while (++i < f->r_no)
			free(f->edgetable[i]);
		free(f->edgetable);
	}
	free(f);
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	exit(0);
}
