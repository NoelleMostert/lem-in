/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joiner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:13:49 by nmostert          #+#    #+#             */
/*   Updated: 2018/09/27 13:23:41 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*joiner(char *s1, char *s2, int clean)
{
	char *s;
	char *new;

	s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1[0] == 0)
	{
		free(s);
		free(s1);
		new = strdup(s2);
		return (new);
	}
	ft_strcat(s, s1);
	ft_strcat(s, "\n");
	ft_strcat(s, s2);
	ft_strdel(&s1);
	(clean) ? ft_strdel(&s2) : 0;
	return (s);
}
