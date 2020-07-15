/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:25:16 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/15 21:37:16 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *arr;

	if (!s || len > (len + 1))
		return (NULL);
	arr = (char *)ft_memalloc(len + 1);
	if (!arr)
		return (NULL);
	ft_strncpy(arr, &s[start], len);
	return (arr);
}
