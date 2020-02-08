/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:22:25 by eflorean          #+#    #+#             */
/*   Updated: 2019/09/20 12:53:34 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	z;
	int		b;

	i = 0;
	if (*needle == '\0')
		return (char *)(haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		z = i;
		b = 1;
		while (needle[j] && b)
		{
			if (!(haystack[z] == needle[j] && z < len))
				b = 0;
			z++;
			j++;
		}
		if (b == 1)
			return (char *)(haystack + i);
		i++;
	}
	return (NULL);
}
