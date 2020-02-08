/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:30:25 by eflorean          #+#    #+#             */
/*   Updated: 2020/01/21 16:17:45 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(const char *str)
{
	int sign;

	sign = 1;
	if (*str == '+')
	{
		sign = 1;
		return (sign);
	}
	if (*str == '-')
	{
		sign = -1;
		return (sign);
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	long unsigned int	sum;
	int					sign;

	sum = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\f' || \
			*str == '\t' || *str == '\v' || *str == '\r')
		str++;
	if (ft_sign(str))
	{
		sign = ft_sign(str);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = (long int)(sum * 10 + *str - '0');
		str++;
		if (sign == -1 && sum > 9223372036854775807)
			return (0);
		if (sign == 1 && sum > 9223372036854775807)
			return (-1);
	}
	return (sign * (int)sum);
}
