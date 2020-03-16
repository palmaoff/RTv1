/*
**  created by eflorean
*/

#include "RTv1.h"

t_vec	vec_norm(t_vec a)
{
	t_vec vec;
	double len;
	len = sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
	vec.x = a.x / len;
	vec.y = a.y / len;
	vec.z = a.z / len;
	return (vec);
}