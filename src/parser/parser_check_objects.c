/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 17:27:14 by wquirrel          #+#    #+#             */
/*   Updated: 2020/06/23 12:59:03 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

typedef enum	e_feature
{
	POS,
	DIR,
	COLOR,
	SIZE,
	ANGLE,
	SPECULAR
}				t_feature;

void 	output_invalid_obj(t_type_o fig)
{
	if (fig == SPHERE)
		output_error("Object \"sphere\" is not valid");
	else if (fig == PLANE)
		output_error("Object \"plane\" is not valid");
	else if (fig == CYLINDER)
		output_error("Object \"cylinder\" is not valid");
	else if (fig == CONE)
		output_error("Object \"cone\" is not valid");
}

t_bool	check_features(t_type_o fig, const t_bool *features)
{
	if ((fig == SPHERE && features[POS] && features[COLOR] && features[SIZE])
	|| (fig == PLANE && features[POS] && features[DIR] && features[COLOR])
	|| (fig == CYLINDER && features[POS] && features[DIR] && features[COLOR]
	&& features[SIZE])
	|| (fig == CONE && features[POS] && features[DIR] && features[COLOR]
	&& features[ANGLE]))
		return (TRUE);
	return (FALSE);
}

void 	assign_feature(char **tmp, t_bool *features)
{
	if (ft_strequ(tmp[0], "pos") && *(tmp + 1))
		features[POS] = check_vec(tmp + 2);
	else if (ft_strequ(tmp[0], "dir") && *(tmp + 1))
		features[DIR] = check_vec(tmp + 2);
	else if (ft_strequ(tmp[0], "color_rgb") && *(tmp + 1))
		features[COLOR] = check_hex(tmp + 2);
	else if (ft_strequ(tmp[0], "size") && *(tmp + 1))
		features[SIZE] = check_int(tmp + 1);
	else if (ft_strequ(tmp[0], "angle") && *(tmp + 1))
		features[ANGLE] = check_float(tmp + 1);
	else if (ft_strequ(tmp[0], "specular"))
		if (!*(tmp + 1) || !(features[SPECULAR] = check_int(tmp + 1)))
			output_error("Value of specular is undefined");
}

t_bool	check_object(int fd, t_type_o fig)
{
	t_bool	*features;
	char	*line;
	char	**tmp;

	features = (t_bool [6]){FALSE};
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(ft_strtrim(line), ' ');
		count_brackets(tmp[0]);
		free(line);
		if (ft_strequ(tmp[0], "}"))
			break;
		assign_feature(tmp, (&features)[0]);
		parser_free_array(tmp);
	}
	parser_free_array(tmp);
	if (check_features(fig, features) == FALSE)
	{
		output_invalid_obj(fig);
		return (FALSE);
	}
	return (TRUE);
}

void	check_objects(int fd)
{
	char			*line;
	unsigned int	obj;

	obj = 0;
	while (get_next_line(fd, &line))
	{
		count_brackets(ft_strtrim(line));
		if (ft_str1trim_equ(line, "};"))
			break;
		if (ft_str1trim_equ(line, "sphere"))
			obj += check_object(fd, SPHERE);
		else if (ft_str1trim_equ(line, "plane"))
			obj += check_object(fd, PLANE);
		else if (ft_str1trim_equ(line, "cylinder"))
			obj += check_object(fd, CYLINDER);
		else if (ft_str1trim_equ(line, "cone"))
			obj += check_object(fd, CONE);
		free(line);
	}
	free(line);
	if (obj == FALSE)
		output_error("Scene doesn't have any valid object");
}