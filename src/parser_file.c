/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:40:19 by wquirrel          #+#    #+#             */
/*   Updated: 2020/06/01 18:38:34 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RTv1.h"

void 	output_error(char *err)
{
	ft_putstr(err);
	exit(1);
}

int		check_coord(const char *line)
{
	int count_c;

	count_c = 0;
	while (*line)
	{
		if (ft_isdigit(*line) && ft_isspace(*(line - 1)))
			count_c++;
		line++;
	}
	if (count_c == 3)
		return (0);
	else
		return (-1);
}

t_state		check_camera(int fd)
{
	t_state coo_state[2];
	char *line;

	while (ft_strequ(line, "}"))
	{
		get_next_line(fd, &line);
		if (ft_strequ(line, "pos") && !check_coord(line))
			coo_state[0] = TRUE;
		else if (ft_strequ(line, "dir") && !check_coord(line))
			coo_state[1] = TRUE;
		if (coo_state[0] == FALSE || coo_state[1] == FALSE)
			return (FALSE);
		else
			return (TRUE);
	}
}

void 	check_scene(int fd)
{
	check_camera(fd);
	check_lights(fd);
}

void	check_file(const int fd)
{
	t_state	scene;
	t_state	objects;
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ft_strequ(line, "scene"))
		{
			check_scene(fd);
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
		output_error("Can't read file\n")
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

int		parser_file(char *file, t_state *cam_flag)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		output_error("Can't open file\n");
	if (check_extension(file) < 0)
		output_error("Wrong extension, need \".rtv1\"\n");
	check_file(fd);
	return (fd);
}