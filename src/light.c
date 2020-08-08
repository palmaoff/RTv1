/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:53:16 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/13 21:29:19 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static	double	specular(t_scene *scene, t_vec l, t_vec n)
{
	t_vec	r;
	t_vec	v;
	int		spec;

	spec = scene->fig[scene->cur].spec;
	if (scene->t > spec)
		return (0);
	v = vec_scale(scene->d, -1);
	r = reflect_ray(l, n);
	return (pow(vec_dot(r, v), spec));
}

static double	shadow(t_scene *scene, t_vec d, t_vec p, int l)
{
	int		i;
	double	t[2];
	t_vec	v;

	i = 0;
	t[1] = 0;
	while (i < scene->n_obj)
	{
		calc_fig(scene, vec_norm(d), p, i);
		t[0] = scene->f_inter[scene->fig[i].shape - 1](scene, i);
		v = vec_scale(vec_norm(d), t[0]);
		if (t[0] > 0.0001 && (vec_dot(v, v) < vec_dot(d, d) ||
			scene->light[l].type == DIRECTIONAL))
			return (0);
		i++;
	}
	return (1);
}

static	double	punch(t_scene *scene, t_vec p)
{
	t_vec	l;
	t_vec	n;
	double	tmp[2];
	int		i;

	i = 0;
	tmp[1] = 0;
	n = scene->f_norm[scene->fig[scene->cur].shape - 1](scene);
	n = vec_norm(n);
	while (i < scene->n_lt)
	{
		if (scene->light[i].type == POINT)
			l = vec_sub(p, scene->light[i].p);
		if (scene->light[i].type == DIRECTIONAL)
			l = scene->light[i].p;
		tmp[0] = vec_dot(vec_norm(l), n);
		if (scene->light[i].type == AMBIENT)
			tmp[1] += scene->light[i].inst;
		else if (tmp[0] > 0 &&
			shadow(scene, vec_scale(l, -1), p, i))
			tmp[1] += (tmp[0] + specular(scene, l, n)) * scene->light[i].inst;
		i++;
	}
	return (tmp[1]);
}

t_color			color(t_scene *scene, double t, t_vec d, t_vec o)
{
	t_color	c;
	double	a;
	t_vec	p;

	p = vec_scale(d, t);
	p = vec_sum(p, o);
	scene->t = t;
	if (t > 1 && t < MAX_T)
	{
		a = punch(scene, p);
		a = (a > 1) ? 1 : a;
		c.r = scene->fig[scene->cur].color.r * a;
		c.g = scene->fig[scene->cur].color.g * a;
		c.b = scene->fig[scene->cur].color.b * a;
	}
	else
		c = init_color(0, 0, 0);
	return (c);
}
