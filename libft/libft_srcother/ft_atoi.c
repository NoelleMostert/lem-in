/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:26:39 by ashulha           #+#    #+#             */
/*   Updated: 2018/09/25 12:35:19 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <libft.h>

static int	ft_spacing(const char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i] == '+' || str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
	{
		if (str[i++] == '+')
			k++;
		if (str[i] == '-')
		{
			k++;
			break ;
		}
	}
	if (k > 1)
		return (-1);
	return (i);
}

static int	ft_minus(const char *str)
{
	if (*str == '-')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int i;
	int minus;
	int number;

	number = 0;
	i = ft_spacing(str);
	if (i < 0)
		return (0);
	minus = ft_minus(str + i);
	if (minus == 1)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number > 469762049 && minus == 0)
			return (-1);
		else if (number > 469762049 && minus == 1)
			return (0);
		number = number * 10 + str[i] - '0';
		i++;
	}
	if (minus == 1)
		number = number * -1;
	return (number);
}*/

#include <libft.h>

int		ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		num;

	i = 0;
	neg = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + ((int)str[i] - '0');
		i++;
	}
	if (neg == 1)
		return (-num);
	return (num);
}
