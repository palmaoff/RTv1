/*
**	created by eflorean
*/

#include "RTv1.h"

double	IntersectSphere(t_vec d, t_scene *scene)
{
	t_vec co;
	double m[6];

	co = vec_sub(scene->cam.orig, scene->sphere.c);
	m[0] = 1;
	m[1] = vec_dot(co, d);
	m[2] = (vec_dot(co, co)) - scene->sphere.r * scene->sphere.r;
	m[3] = m[1] * m[1] - m[0] * m[2];
	if (m[3] < 0)
		return (0);
	m[4] = (-m[1] + sqrtf(m[3])) / m[0];
	m[5] = (-m[1] - sqrtf(m[3])) / m[0];
	if (m[4] < 1 && m[5] < 1)
		return (0);
	return ((m[4] < m[5] || m[5] < 1.0) ? m[4] : m[5]);
}

t_vec   sphere_norm(t_scene *scene)
{
    t_vec vec;
    t_vec p;

    p = vec_scale(scene->d, scene->t);
    p = vec_sum(p, scene->cam.orig);
    vec = vec_sub(scene->sphere.c, p);
    return (vec);
}