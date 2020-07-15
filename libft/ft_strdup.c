/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:48:49 by eflorean          #+#    #+#             */
/*   Updated: 2020/07/15 18:19:39 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	unsigned char	*s;
	int				i;

	i = 0;
	s = (unsigned char *)malloc(sizeof(unsigned char) * (ft_strlen(src) + 1));
	if (!s)
		return (0);
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (char *)(s);
}
