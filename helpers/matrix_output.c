/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:37:04 by nmostert          #+#    #+#             */
/*   Updated: 2018/09/27 13:37:12 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	top(t_map *f)
{
	int i;

	i = -1;
	ft_putstr("\n\n");
	ft_putstr("\t   ");
	while (++i < f->r_no)
	{
		ft_putchar(' ');
		ft_putnbr((i > 9) ? (i % 10) : i);
	}
	ft_putstr("\n\n");
}

void		matrix_output(t_map *f)
{
	int i;
	int j;

	top(f);
	i = -1;
	while (++i < f->r_no)
	{
		ft_putchar('\t');
		ft_putnbr((i > 9) ? (i % 10) : i);
		ft_putstr("   ");
		j = -1;
		while (++j < f->r_no)
		{
			ft_putnbr(f->edgetable[i][j]);
			ft_putchar(' ');
		}
		ft_putstr("\t\t");
		ft_putchar('[');
		ft_putnbr_clr(MAGENTA, i);
		ft_putstr("] -  ");
		ft_putendl(f->rooms[i]);
	}
	ft_putstr("\n\n");
}
