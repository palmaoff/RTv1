/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:15:36 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/13 22:49:53 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void *arr;

	arr = (void *)malloc(size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size);
	return (arr);
}
