/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:21:12 by wquirrel          #+#    #+#             */
/*   Updated: 2020/04/27 17:32:47 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	parser_identify(t_type_o id, t_type_o *shape)
{
	if (id == SPHERE)
		*shape = SPHERE;
	else if(id == PLANE)
		*shape = PLANE;
	else if(id == CYLINDER)
		*shape = CYLINDER;
	else if(id == CONE)
		*shape = CONE;
}

void	parser_object(t_figure *obj, int fd, t_type_o id)
{
	char *line;
	char **tmp;

	parser_identify(id, &obj->shape);
	while(get_next_line(fd, &line))
	{
		if(ft_strequ(ft_strtrim(line), "}"))
			break;
		tmp = ft_strsplit(line, ' ');
		free(line);
		if(ft_strequ(ft_strtrim(tmp[0]), "pos"))
			parser_get_vec(&obj->c, tmp + 1);
		else if(ft_strequ(ft_strtrim(tmp[0]), "dir"))
			parser_get_vec(&obj->v, tmp + 1);
		else if(ft_strequ(ft_strtrim(tmp[0]), "color"))
			parser_get_color(&obj->color, tmp + 2);
		else if(ft_strequ(ft_strtrim(tmp[0]), "size"))
			obj->k = ft_atoi(tmp[2]);
		else if(ft_strequ(ft_strtrim(tmp[0]), "angle"))
			obj->k = ft_atof(tmp[2]);
		parser_free_array(tmp);
	}
	if (line)
		free(line);
	parser_free_array(tmp);
}

void	parser_objects(t_scene *scene, int fd)
{
	unsigned int	i;
	char *line;

	i = 0;
	while(get_next_line(fd, &line) && i != scene->n_obj)
	{
		if(ft_strequ(ft_strtrim(line), "sphere") || ft_strequ(ft_strtrim(line), "plane")
		   || ft_strequ(ft_strtrim(line), "cylinder") || ft_strequ(ft_strtrim(line), "cone"))
		{
			if(ft_strequ(ft_strtrim(line), "sphere"))
				parser_object(&scene->fig[i], fd, SPHERE);
			else if(ft_strequ(ft_strtrim(line), "plane"))
				parser_object(&scene->fig[i], fd, PLANE);
			else if(ft_strequ(ft_strtrim(line), "cylinder"))
				parser_object(&scene->fig[i], fd, CYLINDER);
			else if(ft_strequ(ft_strtrim(line), "cone"))
				parser_object(&scene->fig[i], fd, CONE);
			i++;
		}
	}
}
