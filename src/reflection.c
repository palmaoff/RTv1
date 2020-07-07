/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:06:08 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/07 17:06:08 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vec	reflect_ray(t_vec l, t_vec n)
{
	t_vec vec;

	vec = vec_sub(vec_scale(n, 2 * vec_dot(n, l)), l);
	vec = vec_norm(vec);
	return (vec);
}

t_color	reflected_color(t_scene *scene, double t, t_vec d, int depth)
{
	t_vec p;
	t_vec r;

	r = reflect_ray(vec_scale(d, -1),
		vec_norm(scene->f_norm[scene->fig[scene->cur].shape - 1](scene)));
	p = vec_scale(d, t);
	p = vec_sum(p, scene->cam.orig);
	return (ray(scene, r, p, depth - 1));
}
