/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 11:18:33 by nmostert          #+#    #+#             */
/*   Updated: 2018/09/04 07:35:24 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_clr(char const *clr, char const *str)
{
	ft_putstr(clr);
	ft_putstr(str);
	ft_putstr(DEFAULT_FRONT);
}
