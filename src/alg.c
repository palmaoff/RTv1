/*
**	alg.c
**	created by eflorean
*/

#include "RTv1.h"

static	t_vec	viewpoint(double x, double y, t_scene *scene)
{
	t_vec d;
	double rot;
	double angl;

	angl = 0.577350;
	(void)scene; // change parameters
	rot =  (double)WIDTH / (double)HEIGHT;
	d.x = (2.0 * (x + 0.5) / WIDTH - 1) * rot * angl * scene->cam.ori;
	d.y = (1 - 2.0 * (y + 0.5) / HEIGHT) * angl;
	d.z = scene->cam.ori;
	rotate(scene->cam, &d);
	return (d);
}

t_color ray_too(t_scene *scene, t_vec d)
{
    t_color c;
    double t;
    double mint;
    int i;

    i = 0;
    mint = 0;
    while (i < scene->n_obj)
    {
        if (((t = scene->f_inter[scene->fig[i].shape - 1](d, scene, i, scene->cam.orig)) < mint || mint == 0) && t > 1)
        {
            mint = t;
            scene->cur = i;
        }
        i++;
    }
    c = color(scene, mint, d);
    return (c);
}

void	draw(t_scene *scene, t_sdl *sdl)
{
	float i;
	float j;
	t_vec d;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			scene->cam.dir = vec_norm(scene->cam.dir);
			d = viewpoint(i, j, scene);
			d = vec_norm(d);
			scene->color = ray_too(scene, d);
			SDL_SetRenderDrawColor(sdl->render, scene->color.r, scene->color.g, scene->color.b, 1);
			SDL_RenderDrawPoint(sdl->render, i, j);
			j++;
		}
		i++;
	}
}
