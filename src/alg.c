/*
** created by eflorean
*/

#include "RTv1.h"

float scal(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec minus(t_vec a, t_vec b)
{
	t_vec c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

static	t_vec	viewpoint(float x, float y, t_scene *scene)
{
	t_vec d;

	d.x = x * scene->w / WIDTH - scene->w / 2; 
	d.y = scene->h / 2 - y * scene->h / HEIGHT;
	d.z = 1;
	return (d);
}

float	IntersectSphere(t_vec d, t_scene *scene)
{
	float a;
	float b;
	float c;
	t_vec oc;
	float discr;
	float t1;
	float t2;

	oc = minus(scene->o, scene->c);
	a = scal(d, d);
	b = scal(oc, d);
	c = scal(oc, oc) - scene->r * scene->r;
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
			scene->color = ray(scene, d);
			SDL_SetRenderDrawColor(sdl->render, scene->color.r, scene->color.g, scene->color.b, 1);
			SDL_RenderDrawPoint(sdl->render, i, j);
			j++;
		}
		i++;
	}
}
