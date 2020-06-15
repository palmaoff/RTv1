/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:37:05 by eflorean          #+#    #+#             */
/*   Updated: 2020/06/15 16:27:29 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647

int	ft_htoi(const char *hex)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (hex[i] == '\0' || hex[i] == 27 || hex[i] == '\200'
		|| (hex[i] != '0' && hex[i + 1] != 'x'))
		return (INT_MIN);
	i = 2;
	while (hex[i] != '\0')
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			res = 16 * res + (hex[i] - '0');
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			res = 16 * res + (hex[i] - 87);
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			res = 16 * res + (hex[i] - 55);
		else
			return (INT_MIN);
		i++;
	}
	return (res);
}
