/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:40:19 by wquirrel          #+#    #+#             */
/*   Updated: 2020/06/22 18:32:49 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RTv1.h"

void 	output_error(char *err)
{
	ft_putstr(err);
	exit(1);
}

void	check_file(const int fd, t_bool *cam_f)
{
	t_bool	scene;
	t_bool	objects;
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ft_strequ(line, "scene"))
		{
			check_scene(fd, cam_f);
			scene = TRUE;
		}
		else if(ft_strequ(line, "objects"))
		{
			check_objects(fd);
			objects = TRUE;
		}
		free(line);
	}
	if (scene == FALSE)
		output_error("Add \"scene\" tag\n");
	else if(objects == FALSE)
		output_error("Add \"objects\" tag\n");
	else if(ret < 0)
		output_error("Can't read file\n");
}

int		check_extension(const char *file)
{
	while (*file != '.' && *file)
		file++;
	if (*file != '.')
		return(-1);
	file++;
	if (ft_strequ("rtv1", file) == 0)
		return(-1);
	return(0);
}

void parser_file(char *file, t_bool *cam_f)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		output_error("Can't open file\n");
	if (check_extension(file) < 0)
		output_error("Wrong extension, need \".rtv1\"\n");
	check_file(fd, cam_f);
	close(fd);
}