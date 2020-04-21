/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:40:56 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/24 19:09:20 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	void	ft_plus(int *n, int *i)
{
	*n = 1;
	*i = ++*i;
}

static	void	ft_minus(int *n, int *i)
{
	*n = -1;
	*i = ++*i;
}

int				ft_atoi(const char *str)
{
	unsigned long long	res;
	int					i;
	int					n;

	i = -1;
	n = 1;
	res = 0;
	while (str[++i] <= 32)
		if (str[i] == '\0' || str[i] == 27 || str[i] == '\200')
			return (0);
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
		ft_minus(&n, &i);
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		ft_plus(&n, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res >= 9223372036854775807ULL && n == 1)
		return (-1);
	else if (res >= 9223372036854775808ULL && n == -1)
		return (0);
	return (res * n);
}
