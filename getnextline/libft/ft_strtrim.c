/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:50:39 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/17 19:39:24 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*arr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]) == 1)
	{
		i++;
		if (s[i] == '\0')
			return (arr = ft_strnew(1));
	}
	j = ft_strlen(s) - 1;
	while (ft_isspace(s[j]) == 1)
		j--;
	arr = ft_strsub(s, i, j - i + 1);
	if (!arr)
		return (NULL);
	return (arr);
}
