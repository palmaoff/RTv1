/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:51:26 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/15 15:43:24 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	intersect_sphere(t_scene *scene, int i)
{
	double m[6];

	m[1] = scene->fig[i].oc_d;
	m[2] = scene->fig[i].oc_oc - scene->fig[i].k_k;
	m[3] = m[1] * m[1] - m[2];
	if (m[3] < 0)
		return (0);
	m[4] = -m[1] + sqrtf(m[3]);
	m[5] = -m[1] - sqrtf(m[3]);
	if (m[4] < m[5] && m[4] >= 0)
		return (m[4]);
	return (m[5] >= 0) ? (m[5]) : 0;
}

t_vec	sphere_norm(t_scene *scene)
{
	t_vec vec;
	t_vec p;

	p = vec_scale(scene->d, scene->t);
	p = vec_sum(p, scene->cam.orig);
	vec = vec_sub(scene->fig[scene->cur].c, p);
	vec = vec_norm(vec);
	if (vec_dot(vec, scene->d) < 0)
		return (vec_scale(vec, -1));
	return (vec);
}
