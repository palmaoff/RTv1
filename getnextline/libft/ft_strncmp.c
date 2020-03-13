/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:53:24 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/12 18:00:38 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < (int)n - 1)
	{
		if (s1[i] != s2[i])
		{
			c = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (c);
		}
		else
			i++;
	}
	c = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (c);
}
