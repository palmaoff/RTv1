/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:49:29 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/24 19:03:59 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *curr;
	t_list *next;

	if (alst && del)
	{
		curr = *alst;
		while (curr)
		{
			next = curr->next;
			del(curr->content, curr->content_size);
			free(curr);
			curr = next;
		}
		*alst = NULL;
	}
}
