/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:15:24 by nmostert          #+#    #+#             */
/*   Updated: 2018/09/26 13:15:26 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ant_counter(t_map *f, char *line)
{
	int		i;
	char	*s;

	i = 0;
	f->begun = 1;
	f->a_list = joiner(f->a_list, line, 0);
	if (line[0] == '#')
		return ;
	s = ft_strtrim(line);
	if ((f->a_no = ft_atoi(s)) <= 0)
		leaveandfree(f, 1);
	while (s[i] != '\n' && s[i] != 0)
	{
		if (!ft_isdigit(s[i++]))
			leaveandfree(f, 1);
	}
}
