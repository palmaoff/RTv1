/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:38:07 by eflorean          #+#    #+#             */
/*   Updated: 2019/09/16 13:21:23 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*d;
	int		i;

	if (s == NULL)
		return (0);
	d = (char *)malloc(len + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (len != 0)
	{
		d[i] = s[start];
		i++;
		start++;
		len--;
	}
	d[i] = 0;
	return (d);
}
