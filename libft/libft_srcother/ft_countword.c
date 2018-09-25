/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:16:18 by ashulha           #+#    #+#             */
/*   Updated: 2018/09/25 12:09:43 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_countword(const char *str, int c)
{
	int num;
	int i;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c)
				i++;
			num++;
		}
		i++;
	}
	return (num);
}
