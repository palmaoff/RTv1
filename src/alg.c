/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:08:22 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/07 17:08:25 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

static	t_vec	viewpoint(double x, double y, t_scene *scene)
{
	t_vec	d;
	double	rot;
	double	angl;

	angl = 0.577350;
	rot = (double)WIDTH / (double)HEIGHT;
	d.x = (2.0 * (x + 0.5) / WIDTH - 1) * rot * angl;
	d.y = (1 - 2.0 * (y + 0.5) / HEIGHT) * angl;
	d.z = 1;
	rotate(scene->cam, &d);
	return (d);
}

t_color			ray(t_scene *scene, t_vec d, t_vec o, int depth)
{
	t_color	c[2];
	double	t;
	double	mint;
	int		i;

	i = 0;
	mint = 0;
	while (i < scene->n_obj)
	{
		calc_fig(scene, d, o, i);
		t = scene->f_inter[scene->fig[i].shape - 1]
(d, scene, i, vec_sub(o, scene->fig[i].c));
		if ((t < mint || mint == 0) && t > 1)
		{
			mint = t;
			scene->cur = i;
		}
		i++;
	}
	c[0] = color(scene, mint, d, o);
	if (depth <= 0 || mint == 0)
		return (c[0]);
	c[0] = color_scale(c[0], 0.7);
	c[1] = color_scale(reflected_color(scene, mint, d, depth), 0.3);
	return (color_sum(c[0], c[1]));
}

void			draw(t_scene *scene, t_sdl *sdl)
{
	float i;
	float j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			scene->cam.dir = vec_norm(scene->cam.dir);
			scene->d = viewpoint(i, j, scene);
			scene->d = vec_norm(scene->d);
			scene->color = ray(scene, scene->d, scene->cam.orig, 0);
			SDL_SetRenderDrawColor(sdl->render, scene->color.r,
				scene->color.g, scene->color.b, 1);
			SDL_RenderDrawPoint(sdl->render, i, j);
			j++;
		}
		i++;
	}
}
