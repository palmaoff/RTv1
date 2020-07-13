/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:34:35 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/18 16:46:46 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t len_n;

	i = 0;
	len_n = ft_strlen(needle);
	if (needle[0] == '\0' || ft_strcmp(haystack, needle) == 0
			|| (!haystack && !needle && len == 0))
		return ((char *)haystack);
	else if (len == 0 && haystack && needle)
		return (NULL);
	if (len_n > len)
		return (NULL);
	while (i != len && haystack[i] != '\0' && (len_n + i) <= len)
		if (ft_strncmp(&haystack[i], needle, len_n) == 0)
			return ((char *)haystack + i);
		else
			i++;
	return (NULL);
}
