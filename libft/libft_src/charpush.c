/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:17:15 by angonyam          #+#    #+#             */
/*   Updated: 2018/09/27 14:11:13 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*charpush(char *str, char c)
{
	int		i;
	char	*new;

	i = 0;
	if (str == NULL)
	{
		new = (char*)malloc(sizeof(char) * 2);
		new[0] = c;
		new[1] = '\0';
	}
	else
	{
		new = (char*)malloc(sizeof(char) * ft_strlen(str) + 2);
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
		new[i] = c;
		new[++i] = '\0';
		free(str);
	}
	return (new);
}
