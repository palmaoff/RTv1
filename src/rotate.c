/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:49:17 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/10 19:28:24 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotate(t_camera cam, t_vec *d)
{
	double pre_y;
	double pre_x;
	double pre_z;

	pre_y = d->y;
	d->y = pre_y * cos(cam.x_r) + d->z * sin(cam.x_r);
	d->z = -pre_y * sin(cam.x_r) + d->z * cos(cam.x_r);
	pre_z = d->z;
	d->z = -d->x * sin(cam.y_r) + pre_z * cos(cam.y_r);
	d->x = pre_z * sin(cam.y_r) + d->x * cos(cam.y_r);
	pre_x = d->x;
	d->x = pre_x * cos(cam.z_r) - d->y * sin(cam.z_r);
	d->y = pre_x * sin(cam.z_r) + d->y * cos(cam.z_r);
}
