/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:30:03 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/17 18:02:24 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s;
	char	*arr;

	if ((!s1 && !s2) || (!s1 && s2) || (s1 && !s2))
		return (NULL);
	len_s = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!arr)
		return (NULL);
	arr = ft_strcpy(arr, s1);
	arr = ft_strcat(arr, s2);
	return (arr);
}
