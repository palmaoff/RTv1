/*
**  created by eflorean
*/

#include "RTv1.h"

double vec_dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}