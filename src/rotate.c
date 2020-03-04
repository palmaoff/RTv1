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
	*y = pre_y * cos(cam.dir.x) + *z * sin(cam.dir.x);
	*z = -pre_y * sin(cam.dir.x) + *z * cos(cam.dir.x);

	pre_z = *z;
	*z = *x * sin(cam.dir.y) + pre_z * cos(cam.dir.y);
	*x = pre_z * sin(cam.dir.y) + *x * cos(cam.dir.y);

	pre_x = *x;
	*x = pre_x * cos(cam.dir.z) - *y * sin(cam.dir.z);
	*y = pre_x * sin(cam.dir.z) + *y * cos(cam.dir.z);
}
