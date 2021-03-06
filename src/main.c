/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:00:38 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/29 17:27:58 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	calc(t_scene *scene)
{
	int		i;
	double	s;

	i = -1;
	s = 0;
	while (++i < scene->n_obj)
	{
		scene->fig[i].color = check_color(scene->fig[i].color);
		scene->fig[i].k_k = scene->fig[i].k * scene->fig[i].k;
	}
	i = -1;
	while (++i < scene->n_lt)
		s += scene->light[i].inst;
	s = (s > 1) ? s : 1;
	i = -1;
	while (++i < scene->n_lt)
	{
		if (scene->light[i].type == DIRECTIONAL)
			scene->light[i].p = vec_norm(scene->light[i].p);
		scene->light[i].inst /= s;
	}
	scene->cam.x_r = 3.14 / 180 * scene->cam.dir.y;
	scene->cam.y_r = 3.14 / 180 * scene->cam.dir.x;
	scene->cam.z_r = 3.14 / 180 * scene->cam.dir.z;
}

void	init(t_sdl *sdl, t_scene *scene)
{
	scene->f_inter[0] = intersect_sphere;
	scene->f_norm[0] = sphere_norm;
	scene->f_inter[1] = intersect_plane;
	scene->f_norm[1] = plane_norm;
	scene->f_inter[2] = intersect_cylinder;
	scene->f_norm[2] = cylinder_norm;
	scene->f_inter[3] = intersect_cone;
	scene->f_norm[3] = cone_norm;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_GetError();
	sdl->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED
			, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	sdl->render = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderClear(sdl->render);
}

void	calc_fig(t_scene *scene, t_vec dir, t_vec o, int i)
{
	t_vec oc;

	scene->d_d = vec_dot(dir, dir);
	oc = vec_sub(o, scene->fig[i].c);
	scene->fig[i].oc_d = vec_dot(oc, dir);
	scene->fig[i].oc_v = vec_dot(oc, scene->fig[i].v);
	scene->fig[i].d_v = vec_dot(dir, scene->fig[i].v);
	scene->fig[i].oc_oc = vec_dot(oc, oc);
	scene->fig[i].v = vec_norm(scene->fig[i].v);
}

int		main(int ac, char *av[])
{
	t_sdl	sdl;
	t_scene	scene;

	scene = (t_scene){0};
	scene.file = av[1];
	parser(&scene, ac);
	output_help();
	init(&sdl, &scene);
	calc(&scene);
	loop(&sdl, &scene);
	free(scene.fig);
	free(scene.light);
	SDL_DestroyRenderer(sdl.render);
	SDL_DestroyWindow(sdl.window);
	SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
	SDL_Quit();
	return (0);
}
