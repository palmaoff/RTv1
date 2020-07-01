/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 18:33:07 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/01 14:26:24 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_bool	check_hex(char **hex)
{
	int h[3];

	h[0] = INT_MIN;
	h[1] = INT_MIN;
	h[2] = INT_MIN;
	if ((h[0] = ft_htoi(hex[0])) == INT_MIN
	|| (h[1] = ft_htoi(hex[1])) == INT_MIN
	|| (h[2] = ft_htoi(hex[2])) == INT_MIN)
		return (FALSE);
	return (TRUE);
}

t_bool	check_float(char **str)
{
	int p;
	int i;

	p = 0;
	i = 0;
	if (!str || !*str)
		return (FALSE);
	while (str[1][i])
	{
		if (str[1][i] == '.')
			p++;
		else if (!ft_isdigit(str[1][i]) && str[1][i] != '-')
			return (FALSE);
		i++;
	}
	if (p > 1)
		return (FALSE);
	return (TRUE);
}

t_bool	check_int(char **str)
{
	int i;

	i = 0;
	if (!str || !*str)
		return (FALSE);
	while (str[1][i])
	{
		if (ft_isdigit(str[1][i]) || str[1][i] == '-')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

t_bool	check_vec(char **vec)
{
	int i;
	int j;

	i = -1;
	if (vec[0] && vec[1] && vec[2])
	{
		while (++i != 3)
		{
			j = -1;
			while (vec[i][++j])
				if (ft_isdigit(vec[i][j]) || vec[i][j] == '-')
					continue;
				else
					return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}
