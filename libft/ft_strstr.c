/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:22:25 by eflorean          #+#    #+#             */
/*   Updated: 2019/11/01 14:31:53 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return (char *)(haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j])
		{
			if (!(haystack[i + j] == needle[j]))
				break ;
			j++;
		}
		if (!needle[j])
			return (char *)(haystack + i);
		i++;
	}
	return (NULL);
}
