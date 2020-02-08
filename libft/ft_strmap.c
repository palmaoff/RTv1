/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:32:55 by eflorean          #+#    #+#             */
/*   Updated: 2019/09/16 12:52:59 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*d;
	size_t	size;

	if (s == NULL || f == NULL)
		return (0);
	size = ft_strlen(s);
	i = 0;
	d = (char *)malloc(size + 1);
	if (!d)
		return (0);
	while (i < size)
	{
		d[i] = f(s[i]);
		i++;
	}
	d[size] = 0;
	return (d);
}
