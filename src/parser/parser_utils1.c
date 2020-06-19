/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:24:09 by wquirrel          #+#    #+#             */
/*   Updated: 2020/04/27 18:07:54 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int 	ft_str1trim_equ(const char *line, const char *str)
{
	return ft_strequ(ft_strtrim(line), str);
}

void 	parser_free_array(char **ar)
{
	int i;

	i = 0;
	if (!ar)
		return ;
	while(ar[i])
	{
		ft_memdel((void **) &ar[i]);
		i++;
	}
	free(ar);
}

void 	parser_get_color(t_color *col, char **tmp)
{
	col->r = ft_htoi(tmp[1]);
	col->g = ft_htoi(tmp[2]);
	col->b = ft_htoi(tmp[3]);
}

void	parser_get_vec(t_vec *vec, char **tmp)
{
	vec->x = ft_atoi(tmp[1]);
	vec->y = ft_atoi(tmp[2]);
	vec->z = ft_atoi(tmp[3]);
}

