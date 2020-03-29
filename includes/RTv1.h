/*
** created by eflorean
*/

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 600
# define HEIGHT 600

# include <stdio.h> // KILL ME
# include "SDL2/SDL.h"
# include <SDL2/SDL_mixer.h>
# include "math.h"

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
	double x_r;
	double y_r;
	double z_r;
}					t_camera;

typedef	struct		s_scene
{
	t_vec	c;
	double	r;
	t_vec   l;
	t_vec   ld;
	t_color color;
	t_camera cam;
}					t_scene;

// vec
double	vec_dot(t_vec a, t_vec b);
t_vec	vec_norm(t_vec a);
t_vec	vec_sub(t_vec a, t_vec b);
t_vec	vec_sum(t_vec a, t_vec b);
t_vec	vec_scale(t_vec a, double t);

// base raytracing
void	draw(t_scene *scene, t_sdl *sdl);
t_vec   init_vec(double x, double y, double z);
void	rotate(t_camera cam, double *x, double *y, double *z);
double	IntersectSphere(t_vec d, t_scene *scene);
t_color color(t_scene *scene, double t, t_vec d);

#endif
