/*
**	created by eflorean
*/

#include "RTv1.h"

void loop(t_sdl *sdl, t_scene *scene)
{
    SDL_Event event;
    int run;
    t_vec vec;

    run = 1;
    draw(scene, sdl);
    SDL_RenderPresent(sdl->render);
    while (run)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                run = 0;
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    run = 0;
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
                if (event.key.keysym.sym == SDLK_UP)
                    scene->cam.x_r += 0.1 * scene->cam.ori;
                if (event.key.keysym.sym == SDLK_DOWN)
                    scene->cam.x_r -= 0.1 * scene->cam.ori;
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
                draw(scene, sdl);
                SDL_RenderPresent(sdl->render);
            }
        }
    }
}

void    init(t_sdl *sdl, t_scene *scene)
{
    t_vec tmp;

    scene->cam.ori = (scene->cam.dir.z < 0) ? -1 : 1;
    scene->cam.dir = vec_norm(scene->cam.dir);
    tmp = vec_norm(init_vec(0, scene->cam.dir.y, scene->cam.dir.z));
    scene->cam.x_r = acos(vec_dot(init_vec(0, 0, scene->cam.ori), tmp));
    tmp = vec_norm(init_vec(scene->cam.dir.x, 0, scene->cam.dir.z));
    scene->cam.y_r = acos(vec_dot(init_vec(0, 0, scene->cam.ori), tmp));
    scene->cam.y_r *= (scene->cam.dir.x * scene->cam.dir.z < 0) ? -1 : 1;
    scene->cam.x_r *= (scene->cam.dir.y * scene->cam.dir.z < 0) ? -1 : 1;
    scene->cam.z_r = 0;
    scene->f_inter[0] = IntersectSphere;
    scene->f_norm[0] = sphere_norm;
    scene->f_inter[1] = IntersectPlane;
    scene->f_norm[1] = plane_norm;
    scene->f_inter[2] = IntersectCylinder;
    scene->f_norm[2] = cylinder_norm;
    scene->f_inter[3] = IntersectCone;
    scene->f_norm[3] = cone_norm;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    	SDL_GetError();
    sdl->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
                           SDL_WINDOW_SHOWN);
    sdl->render = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(sdl->render);
}

int main(int ac, char *av[]) {
    t_sdl sdl;
    t_scene scene;

    scene.file = av[1];
    parser(&scene);
    init(&sdl, &scene);
    loop(&sdl, &scene);
    SDL_DestroyWindow(sdl.window);
    SDL_Quit();
    return (0);
}