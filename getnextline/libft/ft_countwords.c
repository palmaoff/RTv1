/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:13:11 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/16 18:13:52 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int		ft_countwords(const char *str, char d)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (ft_ischar(d, str[i]) != 0 && str[i] != '\0')
			i++;
		if (ft_ischar(d, str[i]) == 0 && str[i] != '\0')
			count++;
		while (ft_ischar(d, str[i]) != 1 && str[i] != '\0')
			i++;
	}
	return (count);
}
