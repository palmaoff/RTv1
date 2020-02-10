/*
** created by eflorean
*/

#include "RTv1.h"

static	t_vec	viewpoint(float x, float y, t_scene *scene)
{
	t_vec d;

	d.x = x; // понять
	d.y = y; // осознать
	d.z = scene->d;
	return (d);
}

void	draw(t_scene *scene)
{
	float i;
	float j;
	t_vec d;

	i = -WIDTH / 2;
	while (i < WIDTH / 2)
	{
		j = -HEIGHT / 2;
		while (j < HEIGHT / 2)
		{
			d = viewpoint(i, j, scene);
			// alg - дописать
			j++;
		}
		i++;
	}
}
