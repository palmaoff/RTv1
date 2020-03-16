/*
**	created by eflorean
*/

#include "RTv1.h"

t_vec vec_sum(t_vec a, t_vec b)
{
	t_vec c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}