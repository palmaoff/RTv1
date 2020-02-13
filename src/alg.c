/*
** created by eflorean
*/

#include "RTv1.h"

static	t_vec	viewpoint(float x, float y, t_scene *scene)
{
	t_vec d;

	d.x = x - scene->w / WIDTH; 
	d.y = y - scene->h / HEIGHT;
	d.z = scene->d;
	return (d);
}

void	draw(t_scene *scene, t_sdl *sdl)
{
	float i;
	float j;
	t_vec d;

	i = -WIDTH / 2;
	while (i < WIDTH / 2)
	{
		j = -HEIGHT / 2;
		while (j < HEIGHT / 2)
		{
			d = viewpoint(i, j, scene);
			// color
			SDL_SetRenderDrawColor(sdl->render, scene->color.r, scene->color.g, scene->color.b, 1);
			j++;
		}
		i++;
	}
}
