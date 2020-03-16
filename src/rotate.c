/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:49:17 by wquirrel          #+#    #+#             */
/*   Updated: 2020/01/17 21:49:20 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	rotate(t_camera cam, double *x, double *y, double *z)
{
	double pre_y;
	double pre_x;
	double pre_z;

	pre_y = *y;
	*y = pre_y * cos(cam.x_r) + *z * sin(cam.x_r);
	*z = -pre_y * sin(cam.x_r) + *z * cos(cam.x_r);

	pre_z = *z;
	*z = -*x * sin(cam.y_r) + pre_z * cos(cam.y_r);
	*x = pre_z * sin(cam.y_r) + *x * cos(cam.y_r);

	pre_x = *x;
	*x = pre_x * cos(cam.z_r) - *y * sin(cam.z_r);
	*y = pre_x * sin(cam.z_r) + *y * cos(cam.z_r);
}
