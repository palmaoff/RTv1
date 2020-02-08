/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:28:25 by eflorean          #+#    #+#             */
/*   Updated: 2019/09/20 13:01:13 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_clear_lst(t_list **start)
{
	t_list *a;

	while (*start)
	{
		a = *start;
		*start = (*start)->next;
		free(a);
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*next;
	t_list	*start;

	if (lst == NULL || f == NULL)
		return (NULL);
	next = f(lst);
	if (!(new = ft_lstnew(next->content, next->content_size)))
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst != NULL)
	{
		next = f(lst);
		new->next = ft_lstnew(next->content, next->content_size);
		if (!new->next)
		{
			free(new->next);
			ft_clear_lst(&start);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
