/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:32:55 by eflorean          #+#    #+#             */
/*   Updated: 2019/09/16 12:53:14 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*d;
	size_t	size;

	if (s == NULL || f == NULL)
		return (0);
	size = ft_strlen(s);
	d = (char *)malloc(size + 1);
	if (!d)
		return (0);
	i = 0;
	while (s[i])
	{
		d[i] = f(i, s[i]);
		i++;
	}
	d[size] = '\0';
	return (d);
}
