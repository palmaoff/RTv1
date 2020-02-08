/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:55:55 by eflorean          #+#    #+#             */
/*   Updated: 2019/09/16 15:47:52 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_size(const char *s)
{
	size_t size;

	size = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (s[size])
		size++;
	if (size == 0)
		return (0);
	size--;
	while (s[size] == ' ' || s[size] == '\t' || s[size] == '\n')
		size--;
	return (++size);
}

char			*ft_strtrim(char const *s)
{
	char	*d;
	size_t	i;
	size_t	size;

	i = 0;
	if (s == NULL)
		return (0);
	size = split_size(s);
	d = (char *)malloc(size + 1);
	if (!d)
		return (0);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	d[size] = 0;
	return (d);
}
