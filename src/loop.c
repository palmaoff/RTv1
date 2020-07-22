/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:29:31 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/10 19:28:23 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		move_keys_too_too(t_scene *scene, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_r)
	{
		free(scene->fig);
		free(scene->light);
		scene->light = NULL;
		scene->fig = NULL;
		parser(scene, 2);
		calc(scene);
	}
}

static	void	move_keys_too(t_scene *scene, SDL_Event event, t_vec vec)
{
	if (event.key.keysym.sym == SDLK_UP)
		scene->cam.x_r += 0.1;
	if (event.key.keysym.sym == SDLK_DOWN)
		scene->cam.x_r -= 0.1;
	if (event.key.keysym.sym == SDLK_RIGHT)
		scene->cam.y_r += 0.1;
	if (event.key.keysym.sym == SDLK_LEFT)
		scene->cam.y_r -= 0.1;
	if (event.key.keysym.sym == 61)
	{
		vec = init_vec(0, 0, 1);
		rotate(scene->cam, &vec);
		scene->cam.orig = vec_sum(scene->cam.orig, vec);
	}
	if (event.key.keysym.sym == 45)
	{
		vec = init_vec(0, 0, 1);
		rotate(scene->cam, &vec);
		scene->cam.orig = vec_sub(scene->cam.orig, vec);
	}
}

static	void	move_keys(t_scene *scene, SDL_Event event, t_vec vec)
{
	if (event.key.keysym.sym == SDLK_d)
	{
		vec = init_vec(0.5, 0, 0);
		rotate(scene->cam, &vec);
		scene->cam.orig = vec_sum(scene->cam.orig, vec);
	}
	if (event.key.keysym.sym == SDLK_a)
	{
		vec = init_vec(-0.5, 0, 0);
		rotate(scene->cam, &vec);
		scene->cam.orig = vec_sum(scene->cam.orig, vec);
	}
	if (event.key.keysym.sym == SDLK_s)
	{
		vec = init_vec(0, -0.5, 0);
		rotate(scene->cam, &vec);
		scene->cam.orig = vec_sum(scene->cam.orig, vec);
	}
	if (event.key.keysym.sym == SDLK_w)
	{
		vec = init_vec(0, 0.5, 0);
		rotate(scene->cam, &vec);
		scene->cam.orig = vec_sum(scene->cam.orig, vec);
	}
}

static	int		keys(t_scene *scene, t_sdl *sdl)
{
	t_vec		vec;
	SDL_Event	event;

	vec = init_vec(0, 0, 0);
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			return (0);
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				return (0);
			move_keys(scene, event, vec);
			move_keys_too(scene, event, vec);
			move_keys_too_too(scene, event);
			draw(scene, sdl);
			SDL_RenderPresent(sdl->render);
		}
	}
	return (1);
}

void			loop(t_sdl *sdl, t_scene *scene)
{
	int run;

	run = 1;
	draw(scene, sdl);
	SDL_RenderPresent(sdl->render);
	while (run)
		run = keys(scene, sdl);
}
