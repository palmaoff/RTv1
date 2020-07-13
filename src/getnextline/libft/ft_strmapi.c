/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:56:24 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/18 16:11:16 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*arr;

	if (!s || !f)
		return (NULL);
	i = 0;
	arr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!arr)
		return (NULL);
	while (s[i] != '\0')
	{
		arr[i] = s[i];
		arr[i] = f(i, arr[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
