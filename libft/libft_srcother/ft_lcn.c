/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:11:50 by ashulha           #+#    #+#             */
/*   Updated: 2018/09/25 12:09:43 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned int	ft_lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm;

	lcm = (a * b) / ft_hcf(a, b);
	return (lcm);
}
