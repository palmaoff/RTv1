/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:48:32 by eflorean          #+#    #+#             */
/*   Updated: 2019/09/19 21:39:22 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst)
	{
		if (content == NULL || content_size == 0)
		{
			lst->content = NULL;
			lst->content_size = 0;
		}
		else
		{
			lst->content = (void *)malloc(content_size);
			if (!lst->content)
			{
				return (0);
				free(lst);
			}
			ft_memcpy(lst->content, content, content_size);
			lst->content_size = content_size;
		}
		lst->next = NULL;
	}
	return (lst);
}
