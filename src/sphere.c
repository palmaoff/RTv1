/*
**	created by eflorean
*/

#include "RTv1.h"

double	IntersectSphere(t_vec d, t_scene *scene)
{
	t_vec co;
	double a;
	double b;
	double c;
	double discr;
	double t1;
	double t2;

	co = vec_sub(scene->cam.orig, scene->c);
	a = 1;
	b = vec_dot(co, d);
	c = (vec_dot(co, co)) - scene->r * scene->r;
	discr = b * b - a * c;
	if (discr < 0)
		return (0);
	t1 = (-b + sqrtf(discr)) / a;
	t2 = (-b - sqrtf(discr)) / a;
	if (t1 < 1 && t2 < 1)
		return (0);
	return ((t1 < t2 || t2 < 1.0) ? t1 : t2);
}