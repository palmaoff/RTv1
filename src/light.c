/*
**	created by eflorean
*/

#include "RTv1.h"

double   punch(t_scene *scene, double t, t_vec d)
{
    t_vec p;
    t_vec l;
    t_vec n;
    double a;

    p = vec_scale(d, t);
    p = vec_sum(p, scene->cam.orig);
    // n = vec_sub(scene->sphere.c, p); // sphere
    // n = scene->plane.v; // plane
    // n = cylinder_norm(d, scene, t); // cylinder
    n = cone_norm(d, scene, t); // cone
    n = vec_norm(n);
    l = vec_sub(p, scene->l);
    l = vec_norm(l);
    a = vec_dot(l, n);
    if (a > 0)
        return (a * 0.6);
    return (0);
}

double   dir(t_scene *scene, double t, t_vec d)
{
    t_vec p;
    t_vec l;
    t_vec n;
    double a;

    p = vec_scale(d, t);
    //n = scene->plane.v;
    n = cone_norm(d, scene, t); // cone
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

    a = 0.2 + punch(scene, t, d) + dir(scene, t, d);
    if (a < 0 || a > 1)
        printf("%d\n", a);
    if (t > 1 && t < 10000)
	{
		c.r = 200 * a;
		c.g = 100 * a;
		c.b = 100 * a;
	}
	else
	{
		c.r = 0;
		c.g = 0;
		c.b = 0;
	}
    return (c);
}