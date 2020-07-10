/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:48:20 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/10 19:28:24 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color	color_scale(t_color a, double b)
{
	t_color color;

	color.r = a.r * b;
	color.g = a.g * b;
	color.b = a.b * b;
	return (color);
}
