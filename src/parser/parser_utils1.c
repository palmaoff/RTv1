/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:24:09 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/01 17:03:10 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

char	**ft_strtrim_split(const char *line, const char c)
{
	char *s;
	char **res;

	s = ft_strtrim(line);
	res = ft_strsplit(s, c);
	free(s);
	return (res);
}

int		ft_str1trim_equ(const char *line, const char *str)
{
	char	*s;
	int		res;

	s = ft_strtrim(line);
	res = ft_strequ(s, str);
	free(s);
	return (res);
}

void	parser_free_array(char **ar)
{
	int i;

	i = 0;
	if (!ar)
		return ;
	while (ar[i])
	{
		ft_memdel((void **)&ar[i]);
		i++;
	}
	free(ar);
}

void	parser_get_color(t_color *col, char **tmp)
{
	col->r = ft_htoi(tmp[0]);
	col->g = ft_htoi(tmp[1]);
	col->b = ft_htoi(tmp[2]);
}

void	parser_get_vec(t_vec *vec, char **tmp)
{
	vec->x = ft_atoi(tmp[1]);
	vec->y = ft_atoi(tmp[2]);
	vec->z = ft_atoi(tmp[3]);
}
