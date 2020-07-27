/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:29:31 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/10 19:28:23 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	correct_queue(void)
{
	SDL_EventState(SDL_KEYDOWN, SDL_DISABLE);
	SDL_EventState(SDL_KEYDOWN, SDL_ENABLE);
	SDL_EventState(SDL_MOUSEMOTION, SDL_DISABLE);
	SDL_EventState(SDL_MOUSEMOTION, SDL_ENABLE);
}
