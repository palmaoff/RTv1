/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 17:27:14 by wquirrel          #+#    #+#             */
/*   Updated: 2020/06/14 22:20:42 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_bool	check_hex(char **hex)
{

}

t_bool	check_object(int fd, t_type_o fig)
{
	t_bool	features[5];
	char	*line;
	char	**tmp;

	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(ft_strtrim(line), ' ');
		free(line);
		if (ft_strequ(tmp[0], "pos"))
			features[0] = check_vec(tmp + 2);
		else if (ft_strequ(ft_strequ(tmp[0], "dir")))
			features[1] = check_vec(tmp + 2);
		else if (ft_strequ(tmp[0], "color"))
			features[2] = check_hex(tmp + 3);
	}

}

void	check_objects(int fd)
{
	char *line;
	t_bool obj;

	while (get_next_line(fd, &line))
	{
		if (ft_str1trim_equ(line, "};"))
			break;
		if (ft_str1trim_equ(line, "sphere"))
			obj = check_object(fd, SPHERE);
		else if (ft_str1trim_equ(line, "plane"))
			obj = check_object(fd, PLANE);
		else if (ft_str1trim_equ(line, "cylinder"))
			obj = check_object(fd, CYLINDER);
		else if (ft_str1trim_equ(line, "cone"))
			obj = check_object(fd, CONE);
		free(line);
	}
	free(line);
	if (obj == FALSE)
		output_error("Scene doesn't have any object");
}