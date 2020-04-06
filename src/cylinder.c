//
// Created by User on 31.03.2020.
//

#include "RTv1.h"

double	IntersectCylinder(t_vec d, t_scene *scene)
{
    t_vec oc;
    double m[6];

    oc = vec_sub(scene->cam.orig, scene->cylinder.c);
    m[0] = vec_dot(d, d) - vec_dot(d, scene->cylinder.v) * vec_dot(d, scene->cylinder.v);
    m[1] = vec_dot(oc, d) - vec_dot(d, scene->cylinder.v) * vec_dot(oc, scene->cylinder.v);
    m[2] = vec_dot(oc, oc) - vec_dot(oc, scene->cylinder.v) * vec_dot(oc, scene->cylinder.v) - scene->cylinder.r * scene->cylinder.r;
    m[3] = m[1] * m[1] - m[0] * m[2];
    if (m[3] < 0)
        return (0);
    m[4] = (-m[1] + sqrtf(m[3])) / m[0];
    m[5] = (-m[1] - sqrtf(m[3])) / m[0];
    if (m[4] < 1 && m[5] < 1)
        return (0);
    return ((m[4] < m[5] || m[5] < 1.0) ? m[4] : m[5]);
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