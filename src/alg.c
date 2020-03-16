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
	d.x = (2.0 * (x + 0.5) / WIDTH - 1) * rot * angl;
	d.y = (1 - 2.0 * (y + 0.5) / HEIGHT) * angl;
	d.z = 1.0;
	rotate(scene->cam, &d.x, &d.y, &d.z);
	return (d);
}

float	IntersectSphere(t_vec d, t_scene *scene)
{
	t_vec co;
	double a;
	double b;
	double c;
	double discr;
	double t1;
	double t2;

	co = vec_sub(scene->cam.orig, scene->c);
	a = 1;
	b = vec_dot(co, d);
	c = (vec_dot(co, co)) - scene->r * scene->r;
	discr = b * b - a * c;
	if (discr < 0)
		return (0);
	t1 = (-b + sqrtf(discr)) / a;
	t2 = (-b - sqrtf(discr)) / a;
	if (t1 < 1 && t2 < 1)
		return (0);
	return ((t1 < t2 || t2 < 1.0) ? t1 : t2);
}

t_color	ray(t_scene *scene, t_vec d)
{
	t_color c;
	float t;

	t = 10000;
	t = IntersectSphere(d, scene);
	if (t > 1 && t < 10000)
	{
		c.r = 200;
		c.g = 100;
		c.b = 100;
	}
	else
	{
		c.r = 0;
		c.g = 0;
		c.b = 0;
	}
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
			scene->color = ray(scene, d);
			SDL_SetRenderDrawColor(sdl->render, scene->color.r, scene->color.g, scene->color.b, 1);
			SDL_RenderDrawPoint(sdl->render, i, j);
			j++;
		}
		i++;
	}
}
