/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:40:19 by wquirrel          #+#    #+#             */
/*   Updated: 2020/06/28 19:14:06 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	output_error(char *err)
{
	ft_putstr(err);
	exit(1);
}

void	check_file(const int fd, t_bool *cam_f, t_bool *s_o)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ft_strequ(line, "scene"))
		{
			count_brackets(ft_strtrim(line));
			check_scene(fd, cam_f);
			s_o[0] = TRUE;
		}
		else if (ft_strequ(line, "objects"))
		{
			check_objects(fd);
			s_o[1] = TRUE;
		}
		free(line);
	}
	if (s_o[0] == FALSE)
		output_error("Add \"scene\" tag\n");
	else if (s_o[1] == FALSE)
		output_error("Add \"objects\" tag or close brackets\n");
	else if (ret < 0)
		output_error("Can't read file\n");
}

int		check_extension(const char *file)
{
	while (*file != '.' && *file)
		file++;
	if (*file != '.')
		return (-1);
	file++;
	if (ft_strequ("rtv1", file) == 0)
		return (-1);
	return (0);
}

void	parser_file(char *file, t_bool *cam_f, int ac)
{
	t_bool	*s_o;
	int		fd;
	int		amount_obj;

	if (ac != 2)
		output_error("Usage: ./rtv1 /*filepath*\n");
	if ((fd = open(file, O_RDONLY)) < 0)
		output_error("Can't open file\n");
	if (check_extension(file) < 0)
		output_error("Wrong file, need \"*filename*.rtv1\"\n");
	s_o = (t_bool[2]){FALSE};
	check_file(fd, cam_f, s_o);
	amount_obj = valid_count_obj(file);
	close(fd);
	if (count_brackets("finish") != 4 + 2 * amount_obj)
		output_error("Please check expected brackets");
}
