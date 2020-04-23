/*
**	created by eflorean
*/

#include "RTv1.h"

double   punch(t_scene *scene, t_vec p)
{
    t_vec l;
    t_vec n;
    double tmp[2];
    int i;

    i = 0;
    tmp[1] = 0;
    p = vec_scale(scene->d, scene->t);
    p = vec_sum(p, scene->cam.orig);
    n = scene->f_norm[scene->cur](scene);
    n = vec_norm(n);
    while (i < scene->n_lt)
    {
        if (scene->light[i].type == POINT)
        {
            l = vec_sub(p, scene->light[i].p);
            l = vec_norm(l);
        }
        if (scene->light[i].type == DIRECTIONAL)
            l = scene->light[i].p;
        tmp[0] = vec_dot(l, n);
        if (tmp[0] > 0)
            tmp[1] += tmp[0] * scene->light[i].inst;
        i++;
    }
    return (tmp[1]);
}

double   dir(t_scene *scene)
{
    t_vec l;
    t_vec n;
    double a;

    n = scene->f_norm[scene->cur](scene);
    n = vec_norm(n);
    l = scene->ld;
    a = vec_dot(l, n);
    if (a > 0)
        return (a * 0.2);
    return (0);
}

double     shadow(t_scene *scene, t_vec p, t_vec d)
{
    int i[2];
    double t[2];
    t_vec v[2];

    i[1] = 0;
    t[1] = 1;
    while (i[1] < scene->n_lt)
    {
        v[1] = vec_sub(scene->light[i[1]].p, p);
        d = vec_norm(v[1]);
        i[0] = 0;
        while (i[0] < 4) // add to another function
        {
            if (scene->fig[i[0]].type != scene->cur)
            {
                t[0] = scene->f_inter[scene->fig[i[0]].type](d, scene, i[0], p);
                v[0] = vec_scale(d, t[0]);
                if (t[0] > 1 && vec_dot(v[0], v[0]) < vec_dot(v[1], v[1]))
                {
                    t[1] -= scene->light[i[1]].inst;
                    break ;
                }
            }
            i[0]++;
        }
        i[1]++;
    }
    return (t[1]);
}

t_color color(t_scene *scene, double t, t_vec d)
{
    t_color c;
    double a;
    t_vec p;

    p = vec_scale(d, t);
    p = vec_sum(p, scene->cam.orig);
    scene->t = t;
    scene->d = d;
    if (t > 1 && t < 10000)
	{
        a = 0.1 + punch(scene, p);
        a *= shadow(scene, p, d);
		c.r = scene->fig[scene->cur].color.r * a;
		c.g = scene->fig[scene->cur].color.g * a;
		c.b = scene->fig[scene->cur].color.b * a;
	}
	else
		c = init_color(0, 0,0);
    return (c);
}