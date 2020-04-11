//
// Created by eflorean on 30.03.2020
//

#include "RTv1.h"

double	IntersectPlane(t_vec d, t_scene *scene, int i)
{
    t_vec oc;
    t_vec n;
    double t;

    oc = vec_sub(scene->cam.orig, scene->fig[i].c);
    n = scene->fig[i].v;
    t = -(vec_dot(oc, n) / vec_dot(d, n));
    return (t);
}

t_vec   plane_norm(t_scene *scene)
{
    return (vec_scale(scene->fig[scene->cur].v, -1));
}
