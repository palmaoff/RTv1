/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:58:24 by wquirrel          #+#    #+#             */
/*   Updated: 2020/06/25 14:46:16 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		count_brackets(char *str)
{
	static int br = 0;

	if (ft_strequ(str, "}") || ft_strequ(str, "{")
	|| ft_strequ(str, "};"))
		br++;
	return (br);
}

int		valid_count_obj(char *file)
{
	char *line;
	int fd;
	int a_obj;

	fd = open(file, O_RDONLY);
	a_obj = 0;
	while(get_next_line(fd, &line))
	{
		if(ft_str1trim_equ(line, "sphere") || ft_str1trim_equ(line, "plane")
		   || ft_str1trim_equ(line, "cylinder") || ft_str1trim_equ(line, "cone")
		   || ft_str1trim_equ(line, "light") || ft_str1trim_equ(line, "camera"))
			a_obj++;
		free(line);
	}
	free(line);
	close(fd);
	return (a_obj);
}