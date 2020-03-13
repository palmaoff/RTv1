/*
** created by eflorean
*/

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 720
# define HEIGHT 720

# include <stdio.h> // KILL ME
# include <fcntl.h>
# include "SDL.h"
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
	double	d;
	t_vec	c;
	double	r;
	t_color color;
	t_camera cam;
}					t_cam;

void	draw(t_cam *scene, t_sdl *sdl);
t_vec   init_vec(double x, double y, double z);
t_vec	minus(t_vec a, t_vec b);
t_vec 	plus(t_vec a, t_vec b);
void	rotate(t_camera cam, double *x, double *y, double *z);
t_vec	normalize(t_vec a);

#endif
