/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:37:34 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/18 16:46:13 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

static	void	ft_freestr(char **arr, int j)
{
	while (j != 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	if (!s)
		return (NULL);
	j = -1;
	i = 0;
	if (!(arr = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (NULL);
	arr[ft_countwords(s, c)] = NULL;
	while (j++ != (ft_countwords(s, c) + 1))
	{
		while (ft_ischar(s[i], c) != 0 && s[i] != '\0')
			i++;
		if (ft_ischar(s[i], c) == 0 && s[i] != '\0')
			if (!(arr[j] = ft_strsub(s, i, ft_wordlen(&s[i], c))))
			{
				ft_freestr(arr, j - 1);
				return (NULL);
			}
		while (ft_ischar(s[i], c) != 1 && s[i] != '\0')
			i++;
	}
	return (arr);
}
