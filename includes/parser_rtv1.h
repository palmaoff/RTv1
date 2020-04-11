/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:14:45 by wquirrel          #+#    #+#             */
/*   Updated: 2020/04/08 18:03:53 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_RTV1_H
# define PARSER_RTV1_H

# include <fcntl.h>
# include <get_next_line.h>

typedef enum	e_type_of_light
{
	DIRECTIONAL
}				t_type_l;

typedef enum	e_objects
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
}				t_type_o;

typedef struct	s_rgb
{
	double r;
	double g;
	double b;
}				t_rgb;

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct	s_obj
{
	t_type_o	shape;
	t_type_l	type;
	t_vec 		pos;
	t_vec		dir;
	int			rad;
	t_rgb 		color;
}				t_obj;

typedef struct	s_cam
{
	t_vec		pos;
	t_vec		dir;
}				t_cam;

typedef struct	s_base
{
	char		*file;
	int			n_lt;
	int			n_obj;
	t_cam		cam;
	t_obj		*obj;
	t_obj		*lights;
}				t_base;

void	parser(t_base *scene);

#endif
