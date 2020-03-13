/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:41:51 by wquirrel          #+#    #+#             */
/*   Updated: 2020/03/13 17:43:53 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_rtv1.h"

int		parser_count_obj(int fd)
{
	char *line;
	char **tmp;
	int count;

	count = 0;
	while(get_next_line(fd, &line))
	{
		if(ft_strequ(line, "sphere") || ft_strequ(line, "plane")
		|| ft_strequ(line, "cylinder") || ft_strequ(line, "cone"))
			count++;
	}
}

int		parser_objects(int fd, t_obj *obj)
{
	int count;
	count = parser_count_obj(fd);
}

int 	parser_scene(int fd, t_base *scene)
{
	char **tmp;
	char *line;
//	char bra;

//	bra = 0;
	while(get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		// foo for brackets
/*		if(ft_strequ(tmp[0], "{"))
			bra++;
		else if(ft_strequ(tmp[0], "}"))
			bra--;*/
		if(ft_strequ(tmp[0], "camera"))
		{
			free(line);
			while (!ft_strequ(tmp[0], "}"))
			{
				get_next_line(fd, &line);
				tmp = ft_strsplit(line, ' ');
				if (ft_strequ(tmp[0], "pos"))
				{
					scene->cam.pos.x = ft_atoi(tmp[2]);
					scene->cam.pos.y = ft_atoi(tmp[3]);
					scene->cam.pos.z = ft_atoi(tmp[4]);
				}
				else if (ft_strequ(tmp[0], "dir"))
				{
					scene->cam.direct.x = ft_atoi(tmp[2]);
					scene->cam.direct.y = ft_atoi(tmp[3]);
					scene->cam.direct.z = ft_atoi(tmp[4]);
				}
				free(tmp);
			}
		}
//		else if()
		while(*tmp)
		{
			free(*tmp);
			tmp++;
		}
		free(tmp);
		free(line);
	}
//	if(bra != 0)
//		return(1);
	return(0);
}

/*int		parser_count_file(char *av)
{
	int len;
	int fd;
	char *line;

	len = 0;
	fd = open(av, O_RDONLY);
	while(get_next_line(fd, &line) > 0)
	{
		len += ft_strlen(line);
		free(line);
	}
	close(fd);
	return(len);
}*/

int		parser_validation()
{
	return (0);
}

void	parser(char *av, t_base *scene)
{
	int fd;

	fd = open(av, O_RDONLY);
	parser_validation();
	parser_scene(fd, scene);
	parser_objects(fd, scene->obj);
}