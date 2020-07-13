/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:17:01 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/22 17:04:58 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

static void	ft_del(void *content, size_t size)
{
	size = 0;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *curr;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	if (!(curr = f(lst)))
		return (NULL);
	new = curr;
	while (lst->next)
	{
		lst = lst->next;
		if (!(curr->next = f(lst)))
		{
			ft_lstdel(&new, &ft_del);
			return (NULL);
		}
		curr = curr->next;
	}
	return (new);
}
