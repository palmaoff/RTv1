/*
**	created by eflorean
*/

#include "RTv1.h"

double   punch(t_scene *scene)
{
    t_vec p;
    t_vec l;
    t_vec n;
    double a;

    p = vec_scale(scene->d, scene->t);
    p = vec_sum(p, scene->cam.orig);
    n = scene->f_norm[scene->cur](scene); // norm
    n = vec_norm(n);
    l = vec_sub(p, scene->l);
    l = vec_norm(l);
    a = vec_dot(l, n);
    if (a > 0)
        return (a * 0.6);
    return (0);
}

double   dir(t_scene *scene)
{
    t_vec l;
    t_vec n;
    double a;

    n = scene->f_norm[scene->cur](scene); // norm
    n = vec_norm(n);
    l = scene->ld;
    a = vec_dot(l, n);
    if (a > 0)
        return (a * 0.2);
    return (0);
}

t_color color(t_scene *scene, double t, t_vec d)
{
    t_color c;
    double a;

    scene->t = t;
    scene->d = d;
    if (t > 1 && t < 10000)
	{
        a = 0.2 + punch(scene) + dir(scene);
		c.r = scene->fig[scene->cur].color.r * a;
		c.g = scene->fig[scene->cur].color.g * a;
		c.b = scene->fig[scene->cur].color.b * a;
	}
	else
	{
		c = init_color(0, 0,0);
	}
    return (c);
}