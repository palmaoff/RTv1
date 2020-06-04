/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:41:51 by wquirrel          #+#    #+#             */
/*   Updated: 2020/05/25 19:13:43 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "parser_rtv1.h"
#include "RTv1.h"


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


void	parser(t_scene *scene)
{
	int fd;

	scene->n_lt = 0;
	scene->n_obj = 0;
	fd = parser_file(scene->file, &scene->cam_flag);
	parser_count_obj(scene);
	parser_scene(scene, fd);
	parser_objects(scene, fd);
	close(fd);
}