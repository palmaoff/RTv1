/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:17:09 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/27 17:17:23 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parser_get_type(t_type_l *type, char **tmp)
{
	if (ft_strequ(tmp[1], "Directional"))
		*type = DIRECTIONAL;
	else if (ft_strequ(tmp[1], "Point"))
		*type = POINT;
	else if (ft_strequ(tmp[1], "Ambient"))
		*type = AMBIENT;
}

void	parser_light(t_light *light, int fd)
{
	char *line;
	char **tmp;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (ft_str1trim_equ(line, "}"))
			break ;
		tmp = ft_strsplit(line, ' ');
		free(line);
		if (ft_str1trim_equ(tmp[0], "type"))
			parser_get_type(&light->type, tmp + 1);
		else if (ft_str1trim_equ(tmp[0], "pos"))
			parser_get_vec(&light->p, tmp + 1);
		else if (ft_str1trim_equ(tmp[0], "intensity"))
			light->inst = ft_atof(tmp[2]);
		parser_free_array(tmp);
	}
	if (line)
		free(line);
}

void	parser_camera(t_scene *scene, int fd)
{
	char *line;
	char **tmp;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (ft_str1trim_equ(line, "}"))
			break ;
		tmp = ft_strsplit(line, ' ');
		free(line);
		if (ft_str1trim_equ(tmp[0], "pos"))
			parser_get_vec(&scene->cam.orig, tmp + 1);
		else if (ft_str1trim_equ(tmp[0], "dir"))
			parser_get_vec(&scene->cam.dir, tmp + 1);
		parser_free_array(tmp);
	}
	if (line)
		free(line);
}

int		parser_scene(t_scene *scene, int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	scene->cam = (t_camera){0};
	while (get_next_line(fd, &line))
	{
		if (ft_strequ(line, "};") || i == scene->n_lt)
			break ;
		if (ft_str1trim_equ(line, "camera") && scene->cam_flag)
			parser_camera(scene, fd);
		else if (ft_str1trim_equ(line, "light"))
		{
			parser_light(&scene->light[i], fd);
			i++;
		}
		free(line);
	}
	if (line)
		free(line);
	return (0);
}
