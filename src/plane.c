/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:47:35 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/07 16:49:04 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

double	intersect_plane(t_vec d, t_scene *scene, int i, t_vec oc)
{
	double t;

	t = -(scene->fig[i].oc_v / scene->fig[i].d_v);
	return (t);
}

t_vec	plane_norm(t_scene *scene)
{
	t_vec vec;

	vec = scene->fig[scene->cur].v;
	if (vec_dot(vec, scene->d) < 0)
		return (vec_scale(vec, -1));
	return (vec);
}
