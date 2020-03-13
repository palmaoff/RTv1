/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:14:45 by wquirrel          #+#    #+#             */
/*   Updated: 2020/03/13 15:02:06 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_RTV1_H
# define PARSER_RTV1_H

# include <fcntl.h>
# include <get_next_line.h>

typedef enum	e_objects
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
}				t_type;

typedef struct	s_rgb
{
	double r;
	double g;
	double b;
}				t_rgb;

typedef struct	s_pos
{
	double	x;
	double	y;
	double	z;
}				t_pos;

typedef struct	s_obj
{
	t_type		type;
	t_pos 		pos;
	int			rad;
	t_rgb 		color;
}				t_obj;

typedef struct	s_cam
{
	t_pos		pos;
	t_pos		direct;
}				t_cam;
typedef struct	s_base
{
	t_cam		cam;
	t_obj		*obj;
}				t_base;
#endif
