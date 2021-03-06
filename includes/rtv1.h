/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 18:53:19 by wquirrel          #+#    #+#             */
/*   Updated: 2020/08/09 16:23:56 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 500
# define HEIGHT 500
# define MAX_T 10000

# define INT_MIN -2147483647-1

# ifdef __APPLE__
#  include "SDL.h"
# else
#  include "SDL2/SDL.h"
# endif

# include "math.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>

typedef enum	e_feature
{
	POS,
	DIR,
	COLOR,
	SIZE,
	ANGLE,
	SPECULAR
}				t_feature;

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_type_of_light
{
	DIRECTIONAL = 1,
	POINT,
	AMBIENT
}				t_type_l;

typedef enum	e_objects
{
	SPHERE = 1,
	PLANE,
	CYLINDER,
	CONE
}				t_type_o;

typedef	struct	s_sdl
{
	SDL_Renderer	*render;
	SDL_Window		*window;
}				t_sdl;

typedef	struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef	struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef	struct	s_camera
{
	double	x_r;
	double	y_r;
	double	z_r;
	t_vec	dir;
	t_vec	orig;
}				t_camera;

typedef struct	s_figure
{
	t_type_o	shape;
	int			spec;
	double		k_k;
	double		d_v;
	double		oc_d;
	double		oc_v;
	double		oc_oc;
	double		k;
	t_color		color;
	t_vec		c;
	t_vec		v;
}				t_figure;

typedef struct	s_light
{
	t_type_l	type;
	double		inst;
	t_vec		p;
}				t_light;

typedef	struct	s_scene
{
	int			n_obj;
	int			n_lt;
	int			cur;
	t_bool		cam_flag;
	char		*file;
	t_light		*light;
	t_figure	*fig;
	double		t;
	double		d_d;
	t_color		color;
	t_vec		d;
	t_vec		(*f_norm[4])(struct s_scene *scene);
	double		(*f_inter[4])
(struct s_scene *scene, int i);
	t_camera	cam;
}				t_scene;

/*
** vec
*/

double			vec_dot(t_vec a, t_vec b);
t_vec			vec_norm(t_vec a);
t_vec			vec_sub(t_vec a, t_vec b);
t_vec			vec_sum(t_vec a, t_vec b);
t_vec			vec_scale(t_vec a, double t);
t_vec			reflect_ray(t_vec l, t_vec n);

/*
** color
*/

t_color			init_color(double r, double g, double b);
t_color			color_sum(t_color a, t_color b);
t_color			color_scale(t_color a, double b);

/*
** base raytracing
*/

void			draw(t_scene *scene, t_sdl *sdl);
t_vec			init_vec(double x, double y, double z);
void			rotate(t_camera cam, t_vec *d);
t_color			color(t_scene *scene, double t, t_vec d, t_vec o);
double			intersect_sphere(t_scene *scene, int i);
double			intersect_plane(t_scene *scene, int i);
double			intersect_cylinder(t_scene *scene, int i);
double			intersect_cone(t_scene *scene, int i);
t_vec			cylinder_norm(t_scene *scene);
t_vec			cone_norm(t_scene *scene);
t_vec			sphere_norm(t_scene *scene);
t_vec			plane_norm(t_scene *scene);
t_color			ray(t_scene *scene, t_vec d, t_vec o, int depth);
void			calc_fig(t_scene *scene, t_vec dir, t_vec o, int i);
void			loop(t_sdl *sdl, t_scene *scene);
void			calc(t_scene *scene);
t_color			reflected_color(t_scene *scene, double t, t_vec d, int depth);
t_vec			reflect_ray(t_vec l, t_vec n);
void			correct_queue(void);
t_color			check_color(t_color c);

/*
** parser
*/

void			parser(t_scene *scene, int ac);
void			parser_file(char *file, t_bool *cam_f, int ac);
void			check_scene(int fd, t_bool *cam_flag);
void			check_objects(int fd);
void			parser_objects(t_scene *scene, int fd);
void			parser_get_vec(t_vec *vec, char **tmp);
void			parser_get_color(t_color *col, char **tmp);
void			parser_free_array(char **ar);
void			output_error(char *err);
void			output_help(void);
t_bool			check_vec(char **vec);
t_bool			check_int(char **str);
t_bool			check_float(char **str);
t_bool			check_hex(char **hex);
char			**ft_strtrim_split(const char *line, const char c);
int				ft_htoi(const char *hex);
int				ft_str1trim_equ(const char *line, const char *str);
int				parser_scene(t_scene *scene, int fd);
int				valid_count_obj(char *file);
int				count_brackets(char *str);
double			ft_atof(const char *str);

#endif
