/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 12:09:37 by eflorean          #+#    #+#             */
/*   Updated: 2019/09/22 12:18:25 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char *)malloc(n * sizeof(unsigned char) + 1);
	if (!s)
		return (0);
	while (src[i] && i < n)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (char *)(s);
}
