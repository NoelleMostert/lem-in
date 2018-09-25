/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hcf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:11:15 by ashulha           #+#    #+#             */
/*   Updated: 2018/09/25 12:09:43 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned int	ft_hcf(unsigned int a, unsigned int b)
{
	unsigned int hcf;
	unsigned int temp;

	hcf = 1;
	temp = 1;
	while (temp <= a && temp <= b)
	{
		if (a % temp == 0 && b % temp == 0)
			hcf = temp;
		temp++;
	}
	return (hcf);
}
