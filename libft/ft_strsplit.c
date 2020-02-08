/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:09:52 by eflorean          #+#    #+#             */
/*   Updated: 2019/09/20 13:06:38 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strchrlen(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	return (i);
}

static int		ft_countwords(const char *s, char c)
{
	int i;

	i = 1;
	while (*s && *s == (unsigned char)c)
		s++;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		i++;
		while (*s == (unsigned char)c)
			s++;
	}
	return (i);
}

static char		**ft_fr(char **d, int i)
{
	while (i >= 0)
	{
		free(d[i]);
		i--;
	}
	free(d);
	return (0);
}

static	void	dfree(char **s)
{
	free(*s);
	*s = NULL;
}

static char		**ft_copy(const char *s, char **d, char c, int words)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < words)
	{
		while (*s == (unsigned char)c)
			s++;
		d[i] = (char *)malloc(ft_strchrlen(s, c) + 1);
		if (!d[i])
			return (ft_fr(d, i - 1));
		j = 0;
		while (*s != (unsigned char)c && *s)
		{
			d[i][j] = *s;
			s++;
			j++;
		}
		if (j == 0)
			dfree(&d[i]);
		else
			d[i][j] = '\0';
		i++;
	}
	return (d);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**d;
	int		words;

	if (s == NULL)
		return (0);
	words = ft_countwords(s, c);
	d = (char **)malloc(words * sizeof(char *));
	if (!d)
		return (0);
	d = ft_copy(s, d, c, words);
	return (char **)(d);
}
