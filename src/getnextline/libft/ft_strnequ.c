/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:28:32 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/17 18:07:47 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if ((!s1 && !s2) || (!s1 && s2) || (s1 && !s2))
		return (0);
	i = 0;
	while (i != n)
	{
		if (s1[i] != s2[i])
			return (0);
		else if (s1[i] == s2[i] && s1[i] == '\0')
			return (1);
		else
			i++;
	}
	return (1);
}
