/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:56:03 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/13 13:40:21 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_d;
	size_t len_s;

	len_s = ft_strlen(src);
	len_d = ft_strnlen(dst, size);
	if (len_d == size)
		return (size + len_s);
	if (len_s < size - len_d)
		ft_strncpy(dst + len_d, (char *)src, len_s + 1);
	else
	{
		ft_strncpy(dst + len_d, (char *)src, size - len_d - 1);
		dst[size - 1] = '\0';
	}
	return (len_d + len_s);
}
