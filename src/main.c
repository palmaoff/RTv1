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
    vec = init_vec(0, 0, 1);
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
                    scene->cam.orig.x += 1;
                if (event.key.keysym.sym == SDLK_a)
                    scene->cam.orig.x -= 1;
                if (event.key.keysym.sym == SDLK_s)
                    scene->cam.orig.y -= 1;
                if (event.key.keysym.sym == SDLK_w)
                    scene->cam.orig.y += 1;
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
                    rotate(scene->cam, &vec.x, &vec.y, &vec.z);
                    scene->cam.orig = vec_sum(scene->cam.orig, vec);
                }
                if (event.key.keysym.sym == 45)
                {
                    vec = init_vec(0, 0, 1);
                    rotate(scene->cam, &vec.x, &vec.y, &vec.z);
                    scene->cam.orig = vec_sub(scene->cam.orig, vec);
                }
                if (event.key.keysym.sym == SDLK_SPACE)
                    printf("%f %f %f\n", scene->cam.orig.x, scene->cam.orig.y, scene->cam.orig.z);
                // printf("%d\n", event.key.keysym.sym);
                draw(scene, sdl);
                SDL_RenderPresent(sdl->render);
            }
                
        }
    }
}

void    init(t_sdl *sdl, t_scene *scene)
{
    // CAMERA
    scene->cam.orig = init_vec(0, 0, 0);
    scene->cam.dir = init_vec(0, 0, 1); // суммировать с векотором (0, 0 , 1)
    scene->cam.x_r = scene->cam.dir.y;
    scene->cam.y_r = scene->cam.dir.x;
    scene->cam.z_r = 0;

    // LIGHT
    scene->l = init_vec(50, 10, 50);
    scene->ld = init_vec(1, 4, -3);
    scene->ld = vec_norm(scene->ld);

    // SPHERE
    scene->sphere.c.x = 0;
    scene->sphere.c.y = 0;
    scene->sphere.c.z = 10;
    scene->sphere.r = 4;

    // PLANE
    scene->plane.p = init_vec(0, 0, 1);
    scene->plane.v = init_vec(1, 1, 0);


    // CYLINDER
    scene->cylinder.c = init_vec(0, 0,20);
    scene->cylinder.v = init_vec(1, -1, 0);
    scene->cylinder.v = vec_norm(scene->cylinder.v);
    scene->cylinder.r = 5;

    // CONE
    scene->cone.c = init_vec(0, 0,20);
    scene->cone.v = init_vec(1, -1, 0);
    scene->cone.v = vec_norm(scene->cone.v);
    scene->cone.k = 0.6;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    	SDL_GetError(); // change it
    sdl->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
                           SDL_WINDOW_SHOWN);
    sdl->render = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(sdl->render);
}

int main(int ac, char *av[]) {
    t_sdl sdl;
    t_scene scene;

    init(&sdl, &scene);
    loop(&sdl, &scene);
    SDL_DestroyWindow(sdl.window);
    SDL_Quit();
    return (0);
}