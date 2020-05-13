/*
**	created by eflorean
*/

#include "RTv1.h"

static double   punch(t_scene *scene, t_vec p)
{
    t_vec l;
    t_vec n;
    double tmp[2];
    int i;

    i = 0;
    tmp[1] = 0;
    p = vec_scale(scene->d, scene->t);
    p = vec_sum(p, scene->cam.orig);
    n = scene->f_norm[scene->fig[scene->cur].shape - 1](scene);
    n = vec_norm(n);
    while (i < scene->n_lt)
    {
        if (scene->light[i].type == POINT)
            l = vec_norm(vec_sub(p, scene->light[i].p));
        if (scene->light[i].type == DIRECTIONAL)
            l = scene->light[i].p;
        tmp[0] = vec_dot(l, n);
        if (tmp[0] > 0)
            tmp[1] += tmp[0] * scene->light[i].inst;
        i++;
    }
    return (tmp[1]);
}

static double  shadow_obj(t_scene *scene, t_vec v1, t_vec p, int j)
{
    int i;
    double t[2];
    t_vec d;
    t_vec v;

    i = 0;
    t[1] = 0;
    d = vec_norm(v1);
    while (i < scene->n_obj)
    {
        if (i != scene->cur)
        {
            t[0] = scene->f_inter[scene->fig[i].shape - 1](d, scene, i, p);
            v = vec_scale(d, t[0]);
            if (t[0] > 1 && vec_dot(v, v) < vec_dot(v1, v1))
            {
                t[1] += scene->light[j].inst;
                return (t[1]);
            }
        }
        i++;
    }
    return (t[1]);
}

static double     shadow(t_scene *scene, t_vec p, t_vec d)
{
    int i[2];
    double t[2];
    t_vec v;

    d = (t_vec){1, 1, 1};
    // erase me
    if(!d.x)
    	return(0);
    i[1] = 0;
    t[1] = 1;
    while (i[1] < scene->n_lt)
    {
        v = vec_sub(scene->light[i[1]].p, p);
        i[0] = 0;
        t[1] -= shadow_obj(scene, v, p, i[1]);
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