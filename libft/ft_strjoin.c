/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:56:13 by eflorean          #+#    #+#             */
/*   Updated: 2019/10/24 15:23:29 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check(char const *s1, char const *s2)
{
	char *s;

	if (s1 == NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL)
		s = (char *)malloc(ft_strlen(s2) + 1);
	else if (s2 == NULL)
		s = (char *)malloc(ft_strlen(s1) + 1);
	else
		s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	return (s);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_check(s1, s2);
	if (!s)
		return (NULL);
	if (s1 != NULL)
		while (*s1 && s1 != NULL)
		{
			s[i] = *s1;
			s1++;
			i++;
		}
	if (s2 != NULL)
		while (*s2 && s2 != NULL)
		{
			s[i] = *s2;
			s2++;
			i++;
		}
	s[i] = '\0';
	return (s);
}
