/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:05:08 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/07 17:05:08 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vec	vec_scale(t_vec a, double t)
{
	a.x *= t;
	a.y *= t;
	a.z *= t;
	return (a);
}
