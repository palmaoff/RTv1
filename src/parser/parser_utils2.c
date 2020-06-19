/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:58:24 by wquirrel          #+#    #+#             */
/*   Updated: 2020/06/17 13:58:24 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_bool	check_hex(char **hex)
{
	int h[3];

	h[0] = INT_MIN;
	h[1] = INT_MIN;
	h[2] = INT_MIN;
	if((h[0] = ft_htoi(hex[0])) == INT_MIN
	   || (h[1] = ft_htoi(hex[1])) == INT_MIN
	   || (h[2] = ft_htoi(hex[2])) == INT_MIN)
		return (FALSE);
	return (TRUE);
}
