/*
**	created by eflorean
*/

#include "RTv1.h"

t_vec vec_scale(t_vec a, double t)
{
	a.x *= t;
	a.y *= t;
	a.z *= t;
	return (a);
}