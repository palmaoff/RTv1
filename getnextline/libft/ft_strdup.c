/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:44:31 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/18 16:06:07 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		count;
	char		*dest;

	i = 0;
	count = 0;
	while (s1[count] != '\0')
	{
		count++;
	}
	if (!(dest = (char*)malloc(sizeof(const char) * (count + 1))))
		return (NULL);
	while (i < count)
	{
		dest[i] = (char)s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
