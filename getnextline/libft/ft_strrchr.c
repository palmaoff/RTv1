/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:05:32 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/16 20:49:40 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s1;

	i = ft_strlen(s);
	s1 = (char *)s;
	while (s1[i] != c)
	{
		if (i == 0)
			return (NULL);
		else
			i--;
	}
	return (&s1[i]);
}
