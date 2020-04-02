//
// Created by User on 01.04.2020.
//

#include "RTv1.h"

double	IntersectCone(t_vec d, t_scene *scene)
{
    t_vec oc;
    double a;
    double b;
    double c;
    double discr;
    double t1;
    double t2;

    oc = vec_sub(scene->cam.orig, scene->cone.c);
    a = vec_dot(d, d) - (1 + scene->cone.k * scene->cone.k) * (vec_dot(d, scene->cone.v) * vec_dot(d, scene->cone.v));
    b = vec_dot(oc, d) - (1 + scene->cone.k * scene->cone.k) * (vec_dot(d, scene->cone.v) * vec_dot(oc, scene->cone.v));
    c = vec_dot(oc, oc) - (1 + scene->cone.k * scene->cone.k) * (vec_dot(oc, scene->cone.v) * vec_dot(oc, scene->cone.v));
    discr = b * b - a * c;
    if (discr < 0)
        return (0);
    t1 = (-b + sqrtf(discr)) / a;
    t2 = (-b - sqrtf(discr)) / a;
    if (t1 < 1 && t2 < 1)
        return (0);
    return ((t1 < t2 || t2 < 1.0) ? t1 : t2);
}

t_vec   cone_norm(t_vec d, t_scene *scene, double t)
{
    t_vec vec;
    double m;
    t_vec oc;

    oc = vec_sub(scene->cam.orig, scene->cone.c);
    m = vec_dot(oc, scene->cone.v) + t * vec_dot(d, scene->cone.v);
    vec = vec_sub(vec_sum(vec_scale(d, t), oc), vec_scale(scene->cone.v, m * (1 + scene->cone.k * scene->cone.k)));
    return (vec);
}