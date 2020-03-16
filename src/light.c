/*
**	created by eflorean
*/

#include "RTv1.h"

t_color color(t_scene *scene, double t)
{
    t_color c;
    float a;

    // a = amb();
    (void)scene;
    if (t > 1 && t < 10000)
	{
		c.r = 200 * a;
		c.g = 100 * a;
		c.b = 100 * a;
	}
	else
	{
		c.r = 0;
		c.g = 0;
		c.b = 0;
	}
    return (c);
}