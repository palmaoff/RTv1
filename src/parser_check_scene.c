/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:31:45 by wquirrel          #+#    #+#             */
/*   Updated: 2020/06/11 17:24:45 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int			check_type_light(char  **type)
{
	if (ft_strequ(type[0], "Directional") || ft_strequ(type[0], "Point"))
		return (1);
	else
		return (0);
}

void 		check_lights(int fd)
{
	char **tmp;
	char *line;
	t_bool features[3];

	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(ft_strtrim(line), ' ');
		free(line);
		if (ft_strequ(tmp[0], "}"))
			break;
		if (ft_strequ(tmp[0], "type") && check_type_light(tmp + 2))
			features[0] = TRUE;
		else if (ft_strequ(tmp[0], "pos") && check_vec(tmp + 2))
			features[1] = TRUE;
		else if (ft_strequ(tmp[0], "intensity")
		&& check_float_int(tmp + 2, "float"))
			features[2] = TRUE;
	}
	parser_free_array(tmp);
	if (features[0] != TRUE || features[1] != TRUE || features[2] != TRUE)
		output_error("Check a light");
}

t_bool		check_camera(int fd)
{
	char *line;
	char **tmp;
	t_bool coo_state[2];

	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(ft_strtrim(line), ' ');
		free(line);
		if (ft_str1trim_equ(tmp[0], "}"))
			break;
		if (ft_strequ(tmp[0], "pos") && check_vec(tmp + 2))
			coo_state[0] = TRUE;
		else if (ft_strequ(tmp[0], "dir") && check_vec(tmp + 2))
			coo_state[1] = TRUE;
		parser_free_array(tmp);
	}
	parser_free_array(tmp);
	if (coo_state[0] == FALSE || coo_state[1] == FALSE)
		return (FALSE);
	else
		return (TRUE);
}

void 	check_scene(int fd, t_bool *cam_flag)
{
	char *line;
	t_bool light;

	while (get_next_line(fd, &line))
	{
		if (ft_str1trim_equ(line, "};"))
			break;
		if (ft_str1trim_equ(line, "camera"))
			*cam_flag = check_camera(fd);
		else if (ft_str1trim_equ(line, "light"))
		{
			check_lights(fd);
			light = TRUE;
		}
		free(line);
	}
	free(line);
	if (light != TRUE)
		output_error("Add 1 or more source of light");
}
