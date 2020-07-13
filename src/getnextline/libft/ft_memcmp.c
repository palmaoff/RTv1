/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:55:10 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/13 13:07:31 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*bs1;
	unsigned char	*bs2;

	i = 0;
	if (n == 0)
		return (0);
	bs1 = (unsigned char *)s1;
	bs2 = (unsigned char *)s2;
	while (i != n)
	{
		if (bs1[i] != bs2[i])
			return (bs1[i] - bs2[i]);
		else
			i++;
	}
	return (0);
}
