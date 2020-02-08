/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:00:05 by eflorean          #+#    #+#             */
/*   Updated: 2019/09/16 15:36:06 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n)
{
	int i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char	*ft_positive(int n)
{
	char	*s;
	int		i;

	i = ft_counter(n);
	s = (char *)malloc(i + 1);
	if (!s)
		return (0);
	s[i] = '\0';
	i--;
	while (i >= 0)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (s);
}

static char	*ft_negative(unsigned int n)
{
	char	*s;
	int		i;

	i = ft_counter(n) + 1;
	s = (char *)malloc(i + 1);
	if (!s)
		return (0);
	s[i] = '\0';
	i--;
	while (i > 0)
	{
		s[i] = n % 10 + '0';
		i--;
		n = n / 10;
	}
	s[i] = '-';
	return (s);
}

char		*ft_itoa(int n)
{
	char *s;

	if (n == 0)
	{
		s = (char *)malloc(2);
		s[0] = '0';
		s[1] = '\0';
	}
	if (n > 0)
		s = ft_positive(n);
	if (n < 0 && n != -2147483648)
		s = ft_negative(-n);
	if (n == -2147483648)
		s = ft_negative((unsigned int)-n);
	return (s);
}
