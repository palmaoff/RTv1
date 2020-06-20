/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:40:10 by wquirrel          #+#    #+#             */
/*   Updated: 2020/04/22 19:52:05 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647

double	ft_atof(const char *str)
{
	double	res;
	double	f;
	int		p;

	res = 0;
	f = 1;
	p = 0;
	if (*str == '\0' || *str == 27 || *str == '\200')
		return (INT_MIN);
	while(*str <= 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		f = (*str == '-') ? -1 : 1;
		str++;
	}
	while(*str)
	{
		if ((*str < '0' || *str > '9') && *str != '.')
			return (1);
		else if (*str == '.')
			p = 1;
		else
		{
			if (p)
				f /= 10.0;
			res = res * 10 + (*str - '0');
		}
		str++;
	}
	return((double)res * f);
}

