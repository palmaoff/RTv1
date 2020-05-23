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
	rot =  (double)WIDTH / (double)HEIGHT;
	d.x = (2.0 * (x + 0.5) / WIDTH - 1) * rot * angl * scene->cam.ori;
	d.y = (1 - 2.0 * (y + 0.5) / HEIGHT) * angl;
	d.z = scene->cam.ori;
	rotate(scene->cam, &d);
	return (d);
}

static t_color reflected_color(t_scene *scene, double t, t_vec d, int depth)
{
    t_vec p;
    t_vec r;

    r = reflect_ray(vec_scale(d, -1), vec_norm(scene->f_norm[scene->fig[scene->cur].shape - 1](scene)));
    p = vec_scale(d, t);
    p = vec_sum(p, scene->cam.orig);
    return (ray(scene, r, p, depth - 1));
}

t_color ray(t_scene *scene, t_vec d, t_vec o, int depth)
{
    t_color c;
    double t;
    double mint;
    int i;

    i = 0;
    mint = 0;
    while (i < scene->n_obj)
    {
        calc_fig(scene, d, o, i);
        if (((t = scene->f_inter[scene->fig[i].shape - 1](d, scene, i, vec_sub(o, scene->fig[i].c))) < mint || mint == 0) && t > 1)
        {
            mint = t;
            scene->cur = i;
        }
        i++;
    }
    c = color(scene, mint, d, o);
    if (depth <= 0 || mint == 0)
        return (c);
    c = color_scale(c, 0.7);
    return (color_sum(c, color_scale(reflected_color(scene, mint, d, depth), 0.3)));
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
			scene->color = ray(scene, d, scene->cam.orig, 0);
			SDL_SetRenderDrawColor(sdl->render, scene->color.r, scene->color.g, scene->color.b, 1);
			SDL_RenderDrawPoint(sdl->render, i, j);
			j++;
		}
		i++;
	}
}
