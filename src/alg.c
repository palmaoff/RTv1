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

t_color	ray(t_scene *scene, t_vec d)
{
	t_color c;
	double t;
	double mint;

	mint = IntersectSphere(d, scene);
	scene->f_norm = sphere_norm;
    scene->color = scene->sphere.color;
    if (((t = IntersectCylinder(d, scene)) < mint && t > 1) || mint == 0)
    {
        mint = t;
        scene->f_norm = cylinder_norm;
        scene->color = scene->cylinder.color;
    }
	if (((t = IntersectCone(d, scene)) < mint && t > 1) || mint == 0)
    {
        mint = t;
        scene->f_norm = cone_norm;
        scene->color = scene->cone.color;
    }
    if (((t = IntersectPlane(d, scene)) < mint && t > 1) || mint == 0)
    {
        mint = t;
        scene->f_norm = plane_norm;
        scene->color = scene->plane.color;
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
			scene->color = ray(scene, d);
			SDL_SetRenderDrawColor(sdl->render, scene->color.r, scene->color.g, scene->color.b, 1);
			SDL_RenderDrawPoint(sdl->render, i, j);
			j++;
		}
		i++;
	}
}
