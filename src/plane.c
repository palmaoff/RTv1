//
// Created by eflorean on 30.03.2020
//

#include "RTv1.h"

double	IntersectPlane(t_vec d, t_scene *scene)
{
    t_vec oc;
    t_vec n;
    double t;

    oc = vec_sub(scene->cam.orig, scene->plane.p);
    n = scene->plane.v;
    t = -(vec_dot(oc, n) / vec_dot(d, n));
    return (t);
}