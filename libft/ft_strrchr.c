/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:59:05 by eflorean          #+#    #+#             */
/*   Updated: 2019/09/11 18:16:46 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*m;

	i = 0;
	m = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			m = (char *)s + i;
		i++;
	}
	if ((char)c == '\0')
		return (char *)(s + i);
	return (m);
}
