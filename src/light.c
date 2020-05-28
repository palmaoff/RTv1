/*
**	created by eflorean
*/

#include "RTv1.h"

t_vec reflect_ray(t_vec l, t_vec n)
{
    t_vec vec;

    vec = vec_sub(vec_scale(n, 2 * vec_dot(n, l)), l);
    vec = vec_norm(vec);
    return (vec);
}

static double specular(t_scene *scene, t_vec l, t_vec n)
{
    t_vec r;
    t_vec v;
//    double spec;

//    spec = scene->fig[scene->cur].spec;
    if (scene->t > 100)
        return (0);
    v = vec_scale(scene->d, -1);
    r = reflect_ray(l, n);
    return (pow(vec_dot(r, v), 100));
}

static double   punch(t_scene *scene, t_vec p, t_vec o)
{
    t_vec l;
    t_vec n;
    double tmp[2];
    int i;

    i = 0;
    tmp[1] = 0;
    p = vec_scale(scene->d, scene->t);
    p = vec_sum(p, o);
    n = scene->f_norm[scene->fig[scene->cur].shape - 1](scene);
    n = vec_norm(n);
    while (i < scene->n_lt)
    {
        if (scene->light[i].type == POINT)
            l = vec_norm(vec_sub(p, scene->light[i].p));
        if (scene->light[i].type == DIRECTIONAL)
            l = scene->light[i].p;
        tmp[0] = vec_dot(l, n);
        if (tmp[0] > 0 )
            tmp[1] += (tmp[0] + specular(scene, l, n)) * scene->light[i].inst;
        i++;
    }
    return (tmp[1]);
}

static double  shadow_obj(t_scene *scene, t_vec d, t_vec p, int j)
{
    int i;
    double t[2];
    t_vec v;

    i = 0;
    t[1] = 0;
    while (i < scene->n_obj)
    {
        calc_fig(scene, vec_norm(d), p, i);
        if (i != scene->cur)
        {
            t[0] = scene->f_inter[scene->fig[i].shape - 1](vec_norm(d), scene, i, vec_sub(p, scene->fig[i].c));
            v = vec_scale(vec_norm(d), t[0]);
            if (t[0] > 0 && vec_dot(v, v) < vec_dot(d, d))
            {
                t[1] += scene->light[j].inst;
                return (t[1]);
            }
        }
        i++;
    }
    return (t[1]);
}

static double     shadow(t_scene *scene, t_vec p)
{
    int i;
    double t;
    t_vec v;

    i = 0;
    t = 1;
    while (i < scene->n_lt)
    {
        v = vec_sub(scene->light[i].p, p);
        t -= shadow_obj(scene, v, p, i);
        i++;
    }
    return (t);
}

t_color color(t_scene *scene, double t, t_vec d, t_vec o)
{
    t_color c;
    double a;
    t_vec p;

    p = vec_scale(d, t);
    p = vec_sum(p, o);
    scene->t = t;
    scene->d = d;

    if (t > 1 && t < MAX_T)
	{
        a = 0.1 + punch(scene, p, o);
        a *= shadow(scene, p);
		c.r = scene->fig[scene->cur].color.r * a;
		c.g = scene->fig[scene->cur].color.g * a;
		c.b = scene->fig[scene->cur].color.b * a;
	}
	else
		c = init_color(0, 0,0);
    return (c);
}