/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 18:54:49 by null              #+#    #+#             */
/*   Updated: 2020/03/27 18:55:15 by null             ###   ########.fr       */
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
	*z = *x * sin(cam.y_r) + pre_z * cos(cam.y_r);
	*x = pre_z * sin(cam.y_r) + *x * cos(cam.y_r);

	pre_x = *x;
	*x = pre_x * cos(0) - *y * sin(0);
	*y = pre_x * sin(0) + *y * cos(0);

	pre_z = *z;
	*z = *x * sin(cam.dir.y) + pre_z * cos(cam.dir.y);
	*x = pre_z * sin(cam.dir.y) + *x * cos(cam.dir.y);

	pre_x = *x;
	*x = pre_x * cos(cam.dir.z) - *y * sin(cam.dir.z);
	*y = pre_x * sin(cam.dir.z) + *y * cos(cam.dir.z);
}
