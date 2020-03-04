/*
**	alg.c
**	created by eflorean
*/

#include "RTv1.h"

double dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	normalize(t_vec a)
{
	t_vec vec;
	double len;
	len = sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
	vec.x = a.x / len;
	vec.y = a.y / len;
	vec.z = a.z / len;
	return (vec);
}

t_vec minus(t_vec a, t_vec b)
{
	t_vec c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_vec plus(t_vec a, t_vec b)
{
	t_vec c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

static	t_vec	viewpoint(double x, double y, t_scene *scene)
{
	t_vec d;
	double rot;

	(void)scene; // change parameters
	rot =  (double)WIDTH / (double)HEIGHT;
	d.x = (2 * ((x + 0.5) / WIDTH) - 1) * rot + scene->cam.dir.x;
	d.y = 1 - 2 * (y + 0.5) / HEIGHT + scene->cam.dir.y;
	d.z = scene->o.z + scene->cam.dir.z;
	// rotate(scene->cam, &d.x, &d.y, &d.z);
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

	co = minus(scene->o, scene->c);
	a = dot(d, d);
	b = dot(co, d);
	c = (dot(co, co)) - scene->r * scene->r;
	discr = b * b - a * c;
	if (discr < 0)
		return (0);
	t1 = (-b + sqrt(discr)) / a;
	t2 = (-b - sqrt(discr)) / a;
	return (t1 < t2 ? t1 : t2);
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
			d = viewpoint(i, j, scene);
			d = minus(d, scene->o);
			d = normalize(d);
			scene->color = ray(scene, d);
			SDL_SetRenderDrawColor(sdl->render, scene->color.r, scene->color.g, scene->color.b, 1);
			SDL_RenderDrawPoint(sdl->render, i, j);
			j++;
		}
		i++;
	}
}
