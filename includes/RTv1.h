/*
** created by eflorean
*/

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 720
# define HEIGHT 720

# include <stdio.h> // KILL ME
#include "SDL.h"

typedef	struct		s_sdl
{
	SDL_Renderer *render;
    SDL_Window* window;
}					t_sdl;

typedef	struct		s_vec
{
	float x;
	float y;
	float z;
}					t_vec;

typedef	struct		s_scene
{
	t_vec	o;
	double	d;
	double	c;
	double	r;
}					t_scene;

#endif
