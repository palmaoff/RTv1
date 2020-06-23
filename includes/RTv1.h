/*
** created by eflorean
*/

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 500
# define HEIGHT 500
# define MAX_T 10000

#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647

# include <stdio.h> // KILL ME
# include "SDL2/SDL.h"
# include "math.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

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

typedef	struct		s_sdl
{
	SDL_Renderer	*render;
    SDL_Window		*window;
}					t_sdl;

typedef	struct		s_vec
{
	double x;
	double y;
	double z;
}					t_vec;

typedef	struct		s_color
{
	int r;
	int g;
	int b;
}					t_color;

typedef	struct		s_camera
{
	t_vec dir;
	t_vec orig;
	double ori;
	double x_r;
	double y_r;
	double z_r;
}					t_camera;

typedef struct      s_figure
{
    t_type_o	shape;
    t_vec   c;
    t_vec	v;
	int	spec;
	double	k;
    t_color color;
    double k_k;
    double d_v;
    double oc_d;
    double oc_v;
    double oc_oc;
}                   t_figure;

typedef struct      s_light
{
    t_type_l type;
    double inst;
    t_vec p;
}                   t_light;

typedef	struct		s_scene
{
    t_light *light;
	t_camera cam;
	t_figure *fig;
    t_vec (*f_norm[4])(struct s_scene *scene);
    double (*f_inter[4])(t_vec d, struct s_scene *scene, int i, t_vec orig);
    t_color color;
    double d_d;
    t_vec   d;
    double  t;
    int cur;
    int n_obj;
    int n_lt;
    char *file;
    t_bool cam_flag;
    t_bool spec_flag;
    // t_bool light_flag;
}					t_scene;

// vec
double	vec_dot(t_vec a, t_vec b);
t_vec	vec_norm(t_vec a);
t_vec	vec_sub(t_vec a, t_vec b);
t_vec	vec_sum(t_vec a, t_vec b);
t_vec	vec_scale(t_vec a, double t);
t_vec   reflect_ray(t_vec l, t_vec n);

// color
t_color init_color(double r, double g, double b);
t_color color_sum(t_color a, t_color b);
t_color color_scale(t_color a, double b);

// base raytracing
void	draw(t_scene *scene, t_sdl *sdl);
t_vec   init_vec(double x, double y, double z);
void	rotate(t_camera cam, t_vec *d);
t_color color(t_scene *scene, double t, t_vec d, t_vec o);
double	IntersectSphere(t_vec d, t_scene *scene, int i, t_vec orig);
double	IntersectPlane(t_vec d, t_scene *scene, int i, t_vec orig);
double	IntersectCylinder(t_vec d, t_scene *scene, int i, t_vec orig);
double	IntersectCone(t_vec d, t_scene *scene, int i, t_vec orig);
t_vec   cylinder_norm(t_scene *scene);
t_vec   cone_norm(t_scene *scene);
t_vec   sphere_norm(t_scene *scene);
t_vec   plane_norm(t_scene *scene);
t_color ray(t_scene *scene, t_vec d, t_vec o, int depth);
void    calc_fig(t_scene *scene, t_vec dir, t_vec o, int i);
void    loop(t_sdl *sdl, t_scene *scene);
void    calc(t_scene *scene);
t_color reflected_color(t_scene *scene, double t, t_vec d, int depth);
t_vec   reflect_ray(t_vec l, t_vec n);

//parser

void	parser(t_scene *scene);
void parser_file(char *file, t_bool *cam_f);
void 	check_scene(int fd, t_bool *cam_flag);
void	check_objects(int fd);
void	parser_objects(t_scene *scene, int fd);
void	parser_get_vec(t_vec *vec, char **tmp);
void 	parser_get_color(t_color *col, char **tmp);
void 	parser_free_array(char **ar);
void 	output_error(char *err);
t_bool	check_vec(char **vec);
t_bool	check_int(char **str);
t_bool	check_float(char **str);
t_bool	check_hex(char **hex);
int		ft_htoi(const char *hex);
int 	ft_str1trim_equ(const char *line, const char *str);
int 	parser_scene(t_scene *scene, int fd);
double	ft_atof(const char *str);


#endif
