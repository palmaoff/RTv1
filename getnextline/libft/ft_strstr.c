/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:45:14 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/17 21:30:23 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	ih;
	char	*haystack1;

	ih = 0;
	haystack1 = (char *)haystack;
	if (needle[0] == '\0' || ft_strcmp(haystack, needle) == 0)
		return (haystack1);
	while (haystack[ih] != '\0')
	{
		if (ft_strncmp(&haystack[ih], needle, ft_strlen(needle)) == 0)
			return (haystack1 + ih);
		else
			ih++;
	}
	return (NULL);
}
