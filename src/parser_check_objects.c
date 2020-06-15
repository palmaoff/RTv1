/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 17:27:14 by wquirrel          #+#    #+#             */
/*   Updated: 2020/06/15 20:42:21 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

typedef enum	e_feature
{
	POS,
	DIR,
	COLOR,
	SIZE,
	ANGLE
}				t_feature;


t_bool	check_hex(char **hex)
{
	int h[3];

	h[0] = INT_MIN;
	h[1] = INT_MIN;
	h[2] = INT_MIN;
	if((h[0] = ft_htoi(hex[0])) == INT_MIN
	|| (h[1] = ft_htoi(hex[1])) == INT_MIN
	|| (h[2] = ft_htoi(hex[2])) == INT_MIN)
		return (FALSE);
	return (TRUE);
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

t_bool	check_object(int fd, t_type_o fig)
{
	t_bool	features[5];
	char	*line;
	char	**tmp;

	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(ft_strtrim(line), ' ');
		free(line);
		if (ft_strequ(tmp[0], "}"))
			break;
		if (ft_strequ(tmp[0], "pos"))
			features[POS] = check_vec(tmp + 2);
		else if (ft_strequ(tmp[0], "dir"))
			features[DIR] = check_vec(tmp + 2);
		else if (ft_strequ(tmp[0], "color"))
			features[COLOR] = check_hex(tmp + 3);
		else if (ft_strequ(tmp[0], "size"))
			features[SIZE] = check_float_int(tmp + 2, "int");
		else if (ft_strequ(tmp[0], "angle"))
			features[ANGLE] = check_float_int(tmp + 2, "float");
		parser_free_array(tmp);
	}
	parser_free_array(tmp);
	if (check_features(fig, features) == FALSE)
		return (FALSE);
	return (TRUE);
}

void	check_objects(int fd)
{
	char *line;
	t_bool obj;

	while (get_next_line(fd, &line))
	{
		if (ft_str1trim_equ(line, "};"))
			break;
		if (ft_str1trim_equ(line, "sphere"))
			obj = check_object(fd, SPHERE);
		else if (ft_str1trim_equ(line, "plane"))
			obj = check_object(fd, PLANE);
		else if (ft_str1trim_equ(line, "cylinder"))
			obj = check_object(fd, CYLINDER);
		else if (ft_str1trim_equ(line, "cone"))
			obj = check_object(fd, CONE);
		free(line);
	}
	free(line);
	if (obj == FALSE)
		output_error("Scene doesn't have any valid object");
}