/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:47:36 by eflorean          #+#    #+#             */
/*   Updated: 2019/09/22 13:07:08 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (!*dst && !*src)
		return (0);
	if (n <= 1)
		return (ft_strlen(src) + n);
	while (dst[i] && i < n)
		i++;
	while (src[j])
	{
		if (i < n - 1)
			dst[i] = src[j];
		else if (i == n - 1)
			dst[i] = '\0';
		j++;
		i++;
	}
	if (i <= n - 1)
		dst[i] = 0;
	return (i);
}
