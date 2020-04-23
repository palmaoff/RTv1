/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:41:51 by wquirrel          #+#    #+#             */
/*   Updated: 2020/04/23 15:08:05 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "parser_rtv1.h"
#include "RTv1.h"

void 	parser_get_color(t_color *col, char **tmp)
{
	col->r = ft_htoi(tmp[1]);
	col->g = ft_htoi(tmp[2]);
	col->b = ft_htoi(tmp[3]);
}

void	parser_get_type(t_type_l *type, char **tmp)
{
	if(ft_strequ(tmp[1], "Directional"))
		*type = DIRECTIONAL;
	else if(ft_strequ(tmp[1], "Point"))
		*type = POINT;
}

void	parser_get_vec(t_vec *vec, char **tmp)
{
	vec->x = ft_atoi(tmp[1]);
	vec->y = ft_atoi(tmp[2]);
	vec->z = ft_atoi(tmp[3]);
}

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
	}
	//free
}

/*
void	parser_sphere(t_obj *obj, int fd)
{
	char *line;
	char **tmp;

	obj->shape = SPHERE;
	while(get_next_line(fd, &line))
	{
		if(ft_strequ(ft_strtrim(line), "}"))
			break;
		tmp = ft_strsplit(line, ' ');
		free(line);
		if(ft_strequ(tmp[0], "pos"))
			parser_get_vec(&obj->pos, tmp + 1);
		else if(ft_strequ(tmp[0], "color"))
			parser_get_color(&obj->color, tmp + 2);
		else if(ft_strequ(tmp[0], "size"))
			obj->size = ft_atoi(tmp[2]);
	}
	//free
}
*/

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

void	parser_light(t_scene *scene, t_light *light, int fd)
{
	char *line;
	char **tmp;

	line = NULL;
	while(get_next_line(fd, &line))
	{
		if(ft_strequ(ft_strtrim(line), "}"))
			break;
		tmp = ft_strsplit(line, ' ');
		free(line);
		if(ft_strequ(ft_strtrim(tmp[0]), "type"))
			parser_get_type(&light->type, tmp + 1);
		else if(ft_strequ(ft_strtrim(tmp[0]), "pos"))
			parser_get_vec(&light->p, tmp + 1);
//		else if(ft_strequ(ft_strtrim(tmp[0]), "dir"))
//			parser_get_vec(&light->dir, tmp + 1);
		else if(ft_strequ(ft_strtrim(tmp[0]), "intensity"))
			light->inst = ft_atof(tmp[2]);
	}
	//free array
	//free tmp
}

void 	parser_camera(t_scene *scene, int fd)
{
	char *line;
	char **tmp;

	line = NULL;
	while (get_next_line(fd, &line))
	{
			if(ft_strequ(ft_strtrim(line), "}"))
				break;
			tmp = ft_strsplit(line, ' ');
			if (ft_strequ(ft_strtrim(tmp[0]), "pos"))
				parser_get_vec(&scene->cam.orig, tmp + 1);
			else if (ft_strequ(ft_strtrim(tmp[0]), "dir"))
				parser_get_vec(&scene->cam.dir, tmp + 1);
			free(tmp);
			//free array
		}
	//free all
/*	while(*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(tmp);
	free(line);*/
}

int 	parser_scene(t_scene *scene, int fd)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	while(get_next_line(fd, &line))
	{
		if(ft_strequ(line, "};") || i == scene->n_lt)
			break;
		if(ft_strequ(ft_strtrim(line), "camera"))
			parser_camera(scene, fd);
		else if(ft_strequ(ft_strtrim(line), "light"))
		{
			parser_light(scene, &scene->light[i], fd);
			i++;
		}
		free(line);
	}
	return(0);
}

void	parser_count_obj(t_scene *scene)
{
	char *line;
	int fd;

	fd = open(scene->file, O_RDONLY);
	while(get_next_line(fd, &line))
	{
		if(ft_strequ(ft_strtrim(line), "sphere") || ft_strequ(ft_strtrim(line), "plane")
		   || ft_strequ(ft_strtrim(line), "cylinder") || ft_strequ(ft_strtrim(line), "cone"))
			scene->n_obj++;
		else if(ft_strequ(ft_strtrim(line), "light"))
			scene->n_lt++;
		free(line);
	}
	scene->fig = ft_memalloc(sizeof(t_figure) * scene->n_obj);
	scene->light = ft_memalloc(sizeof(t_figure) * scene->n_lt);
}

int		parser_validation(char *file)
{
	return (0);
}

void	parser(t_scene *scene)
{
	int fd;

	scene->n_lt = 0;
	scene->n_obj = 0;
	if((fd = open(scene->file, O_RDONLY)) <= 0)
		exit(1);
	parser_validation(scene->file);
	parser_count_obj(scene);
	parser_scene(scene, fd);
	parser_objects(scene, fd);
	close(fd);
}