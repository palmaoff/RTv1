/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:58:34 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/15 18:09:40 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int result;

	if (n < 0)
	{
		result = n * (-1);
		ft_putchar_fd('-', fd);
	}
	else
		result = n;
	if (result == 2147483647)
	{
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483647, fd);
		return ;
	}
	else
	{
		if (result >= 10)
			ft_putnbr_fd(result / 10, fd);
		ft_putchar_fd(result % 10 + '0', fd);
	}
	return ;
}
