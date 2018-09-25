/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:26:57 by nmostert          #+#    #+#             */
/*   Updated: 2018/09/25 13:48:26 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *s1, int n)
{
	int			i;
	int			len;
	char		*str;

	i = 0;
	if (ft_strlen(s1) < n)
		len = ft_strlen(s1);
	else
		len = n;
	if (!(str = (ft_strnew(len))))
		return (0);
	while (s1[i] != '\0' && i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
