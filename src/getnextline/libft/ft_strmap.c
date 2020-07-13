/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:19:37 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/18 16:09:46 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*arr;

	i = 0;
	if (!s || !f)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!arr)
		return (NULL);
	while (s[i] != '\0')
	{
		arr[i] = s[i];
		arr[i] = f(arr[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
