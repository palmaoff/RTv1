/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:40:10 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/01 20:52:59 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	sign(const char *c)
{
	double f;

	f = 1;
	if (*c == '-' || *c == '+')
		f = (*c == '-') ? -1 : 1;
	return (f);
}

double	ft_atof(const char *str)
{
	double	*d;
	int		p;

	d = (double[2]){0};
	p = 0;
	if (*str == '\0' || *str == 27 || *str == '\200')
		return (0);
	while (*str <= 32)
		str++;
	d[1] = sign(str++);
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '.')
			return (1);
		else if (*str == '.')
			p = 1;
		else
		{
			if (p)
				d[1] /= 10.0;
			d[0] = d[0] * 10 + (*str - '0');
		}
		str++;
	}
	return ((double)d[0] * d[1]);
}
