/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:51:10 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/17 21:29:32 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

static	long long	ft_len_int(long long n)
{
	long long tmp;
	long long len;

	if (n < 0)
	{
		len = 1;
		tmp = n * -1;
	}
	else if (n == 0)
		return (1);
	else
	{
		len = 0;
		tmp = n;
	}
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	long long	sign;
	int			i;
	char		*arr;
	long long	n1;

	n1 = (long long)n;
	i = 0;
	if (!(arr = (char *)malloc(sizeof(char) * ft_len_int(n1) + 1)))
		return (NULL);
	if (n == 0)
		return (ft_memset(arr, '0', 1));
	if ((sign = n1) < 0)
		n1 = n1 * -1;
	while (n1 > 0)
	{
		arr[i++] = n1 % 10 + '0';
		n1 = n1 / 10;
	}
	if (sign < 0)
		arr[i++] = '-';
	arr[i] = '\0';
	ft_revstr(arr);
	return (arr);
}
