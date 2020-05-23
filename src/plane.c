//
// Created by eflorean on 30.03.2020
//

#include "RTv1.h"

double	IntersectPlane(t_vec d, t_scene *scene, int i, t_vec oc)
{
    t_vec n;
    double t;

    t = -(scene->fig[i].oc_v / scene->fig[i].d_v);
    return (t);
}

t_vec   plane_norm(t_scene *scene)
{
    t_vec vec;

    vec = scene->fig[scene->cur].v;
    if (sin(vec_dot(vec, scene->d)) < 0)
        return (vec_scale(vec, -1));
    return (vec);
}
