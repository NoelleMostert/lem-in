/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:14:48 by ashulha           #+#    #+#             */
/*   Updated: 2018/09/25 12:09:43 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}