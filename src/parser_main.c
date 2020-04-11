/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:41:51 by wquirrel          #+#    #+#             */
/*   Updated: 2020/04/11 21:36:35 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_rtv1.h"

void	parser_get_type(t_type_l *type, char **tmp)
{
	if(ft_strequ(tmp[1], "Directional"))
		*type = DIRECTIONAL;
}

void	parser_get_vec(t_vec *vec, char **tmp)
{
	vec->x = ft_atoi(tmp[1]);
	vec->y = ft_atoi(tmp[2]);
	vec->z = ft_atoi(tmp[3]);
}

void	parser_light(t_base *scene, t_obj *light, int fd)
{
	char *line;
	char **tmp;

	line = NULL;
	while(get_next_line(fd, &line))
	{
		if(ft_strequ(ft_strtrim(line), "]"))
			break;
		tmp = ft_strsplit(line, ' ');
		free(line);
		if(ft_strequ(tmp[0], "type"))
			parser_get_type(&light->type, tmp + 1);
		else if(ft_strequ(tmp[0], "pos"))
			parser_get_vec(&light->pos, tmp + 1);
		else if(ft_strequ(tmp[0], "dir"))
			parser_get_vec(&light->dir, tmp + 1);
	}
	//free array
	//free tmp
}

void	parser_sphere(t_obj obj, int fd)
{
	char *line;
	char **tmp;

	while(get_next_line(fd, &line))
	{
		if(ft_strequ(line, "pos"))
		{
			tmp = ft_strsplit(line, ' ');
			free(line);
		}
	}
}

void	parser_count_obj(t_base *scene)
{
	char *line;
	t_obj *obj;
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
	scene->obj = (t_obj *)malloc(sizeof(t_obj) * scene->n_obj);
	scene->lights = (t_obj *)malloc(sizeof(t_obj) * scene->n_lt);
}

/*int		parser_objects(int fd, t_obj *obj, char *av)
{
	unsigned int	count;
	unsigned int	i;
	char *line;

	i = 0;

	count = parser_count_obj(fd);
	fd = open(av, O_RDONLY);
	while(get_next_line(fd, &line) && i != count)
	{
		if(ft_strequ(line, "sphere") || ft_strequ(line, "plane")
		   || ft_strequ(line, "cylinder") || ft_strequ(line, "cone"))
		{
			if(ft_strequ(line, "sphere"))
				parser_sphere(obj[i], fd);
			if(ft_strequ(line, "plane"))
				obj[i].shape = PLANE;
			if(ft_strequ(line, "cylinder"))
				obj[i].shape = CYLINDER;
			if(ft_strequ(line, "cone"))
				obj[i].shape = CONE;

			i++;
		}
	}
}*/

void 	parser_camera(t_base *scene, int fd)
{
	char *line;
	char **tmp;

	line = NULL;
	while (get_next_line(fd, &line))
	{
			if(ft_strequ(ft_strtrim(line), "]"))
				break;
			tmp = ft_strsplit(line, ' ');
			if (ft_strequ(tmp[0], "\t\tpos"))
				parser_get_vec(&scene->cam.pos, tmp + 1);
			else if (ft_strequ(tmp[0], "\t\tdir"))
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

int 	parser_scene(t_base *scene, int fd)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	while(get_next_line(fd, &line))
	{
		if(ft_strequ(line, "}") || i == scene->n_lt)
			break;
		if(ft_strequ(ft_strtrim(line), "camera"))
			parser_camera(scene, fd);
		else if(ft_strequ(ft_strtrim(line), "light"))
		{
			parser_light(scene, &scene->lights[i], fd);
			i++;
		}
		free(line);
	}
	return(0);
}


int		parser_validation(char *file)
{
	return (0);
}

void	parser(t_base *scene)
{
	int fd;

	if((fd = open(scene->file, O_RDONLY)) <= 0)
		exit(1);
	parser_validation(scene->file);
	parser_count_obj(scene);
	parser_scene(scene, fd);
	//	parser_objects(scene);
	close(fd);
}