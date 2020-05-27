//
// Created by eflorean on 01.04.2020.
//

#include "RTv1.h"

double	IntersectCone(t_vec d, t_scene *scene, int i, t_vec oc)
{
    double m[6];

    scene->fig[i].v = vec_norm(scene->fig[i].v);
    m[0] = scene->d_d - (1 + scene->fig[i].k_k) * (scene->fig[i].d_v * scene->fig[i].d_v);
    m[1] = scene->fig[i].oc_d - (1 + scene->fig[i].k_k) * (scene->fig[i].d_v * scene->fig[i].oc_v);
    m[2] = scene->fig[i].oc_oc - (1 + scene->fig[i].k_k) * (scene->fig[i].oc_v * scene->fig[i].oc_v);
    m[3] = m[1] * m[1] - m[0] * m[2];
    if (m[3] < 0)
        return (0);
    m[4] = (-m[1] + sqrtf(m[3])) / m[0];
    m[5] = (-m[1] - sqrtf(m[3])) / m[0];
    if (m[4] < 1 && m[5] < 1)
        return (0);
    return (((m[4] < m[5] && m[4] >= 1) || m[5] < 1.0) ? m[4] : m[5]);
}

t_vec   cone_norm(t_scene *scene)
{
    t_vec vec;
    double m;
    t_vec oc;
    t_vec p;

    p = vec_scale(scene->d, scene->t);
    oc = vec_sub(scene->cam.orig, scene->fig[scene->cur].c);
    m = vec_dot(oc, scene->fig[scene->cur].v) + scene->t * vec_dot(scene->d, scene->fig[scene->cur].v);
    vec = vec_sub(vec_sum(p, oc), vec_scale(scene->fig[scene->cur].v, m * (1 + scene->fig[scene->cur].k_k)));
    vec = vec_norm(vec);
    if (vec_dot(vec, scene->d) < 0)
        return (vec_scale(vec, -1));
    return (vec);
}