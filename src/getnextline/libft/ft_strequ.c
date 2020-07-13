/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:07:20 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/17 18:08:15 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	len;
	int		cmp;

	if ((!s1 && !s2) || (!s1 && s2) || (s1 && !s2))
		return (0);
	len = ft_strlen(s1) + 1;
	cmp = ft_strnequ(s1, s2, len);
	return (cmp);
}
