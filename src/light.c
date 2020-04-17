/*
**	created by eflorean
*/

#include "RTv1.h"

double   punch(t_scene *scene, t_vec p)
{
    t_vec l;
    t_vec n;
    double a;
    double tmp;
    int i;

    i = 0;
    a = 0;
    p = vec_scale(scene->d, scene->t);
    p = vec_sum(p, scene->cam.orig);
    n = scene->f_norm[scene->cur](scene);
    n = vec_norm(n);
    while (i < 2)
    {

        l = vec_sub(p, scene->light[i].p);
        l = vec_norm(l);
        tmp = vec_dot(l, n);
        if (tmp > 0)
            a += tmp * scene->light[i].inst;
        i++;
    }
    return (a);
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

double     shadow(t_scene *scene, t_vec p)
{
    t_vec d;
    int i[2];
    double t[2];
    t_vec v[2];

    i[1] = 0;
    t[1] = 1;
    while (i[1] < 2)
    {
        v[1] = vec_sub(scene->light[i[1]].p, p);
        d = vec_norm(v[1]);
        i[0] = 0;
        while (i[0] < 4)
        {
            if (scene->fig[i[0]].type != scene->cur)
            {
                t[0] = scene->f_inter[scene->fig[i[0]].type](d, scene, i[0], p);
                v[0] = vec_scale(d, t[0]);
                if (t[0] > 1 && vec_dot(v[0], v[0]) < vec_dot(v[1], v[1]))
                    t[1] -= scene->light[i[1]].inst;
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
        a = 0.2 + punch(scene, p) + dir(scene);
        a *= shadow(scene, p);
		c.r = scene->fig[scene->cur].color.r * a;
		c.g = scene->fig[scene->cur].color.g * a;
		c.b = scene->fig[scene->cur].color.b * a;
	}
	else
		c = init_color(0, 0,0);
    return (c);
}