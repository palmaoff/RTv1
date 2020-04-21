/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:22:00 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/16 18:26:13 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0' && i != n)
	{
		s1[len] = (char)s2[i];
		i++;
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
