//
// Created by User on 31.03.2020.
//

#include "RTv1.h"

double	IntersectCylinder(t_vec d, t_scene *scene)
{
    t_vec oc;
    double a;
    double b;
    double c;
    double discr;
    double t1;
    double t2;

    oc = vec_sub(scene->cam.orig, scene->cylinder.c);
    a = vec_dot(d, d) - vec_dot(d, scene->cylinder.v) * vec_dot(d, scene->cylinder.v);
    b = vec_dot(oc, d) - vec_dot(d, scene->cylinder.v) * vec_dot(oc, scene->cylinder.v);
    c = vec_dot(oc, oc) - vec_dot(oc, scene->cylinder.v) * vec_dot(oc, scene->cylinder.v) - scene->cylinder.r * scene->cylinder.r;
    discr = b * b - a * c;
    if (discr < 0)
        return (0);
    t1 = (-b + sqrtf(discr)) / a;
    t2 = (-b - sqrtf(discr)) / a;
    if (t1 < 1 && t2 < 1)
        return (0);
    return ((t1 < t2 || t2 < 1.0) ? t1 : t2);
}

t_vec   cylinder_norm(t_scene *scene)
{
    t_vec vec;
    double m;
    t_vec oc;
    t_vec p;

    p = vec_scale(scene->d, scene->t);
    oc = vec_sub(scene->cam.orig, scene->cylinder.c);
    m = vec_dot(oc, scene->cylinder.v) + scene->t * vec_dot(scene->d, scene->cylinder.v);
    vec = vec_sub(vec_sum(p, oc), vec_scale(scene->cylinder.v, m));
    return (vec_scale(vec, -1));
}