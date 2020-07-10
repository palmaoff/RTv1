/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:58:24 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/10 19:28:24 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		count_brackets(char *str)
{
	char		*s;
	static int	br = 0;

	s = ft_strtrim(str);
	if (ft_strequ(s, "}") || ft_strequ(s, "{")
	|| ft_strequ(s, "};"))
		br++;
	else if (ft_strequ(s, "scene"))
		br = 0;
	free(s);
	return (br);
}

int		valid_count_obj(char *file)
{
	char	*line;
	int		fd;
	int		a_obj;

	fd = open(file, O_RDONLY);
	a_obj = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_str1trim_equ(line, "sphere") || ft_str1trim_equ(line, "plane")
		|| ft_str1trim_equ(line, "cylinder") || ft_str1trim_equ(line, "cone")
		|| ft_str1trim_equ(line, "light") || ft_str1trim_equ(line, "camera"))
			a_obj++;
		free(line);
	}
	free(line);
	close(fd);
	return (a_obj);
}
