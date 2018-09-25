/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:27:07 by ashulha           #+#    #+#             */
/*   Updated: 2018/09/25 12:09:43 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strtrim(char const *s)
{
	int		begin;
	int		end;
	char	*str;

	if (!s)
		return (NULL);
	begin = -1;
	end = ft_strlen(s);
	while (ft_isspace(s[++begin]))
		NULL;
	while (ft_isspace(s[--end]))
		NULL;
	str = ft_strsub(s, begin, end - begin + 1);
	return (str);
}
