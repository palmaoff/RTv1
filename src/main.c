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
                    scene->cam.orig.x += 10;
                if (event.key.keysym.sym == SDLK_a)
                    scene->cam.orig.x -= 10;
                if (event.key.keysym.sym == SDLK_s)
                    scene->cam.orig.y -= 10;
                if (event.key.keysym.sym == SDLK_w)
                    scene->cam.orig.y += 10;
                if (event.key.keysym.sym == SDLK_UP)
                {
                    scene->cam.x_r += 0.1;
                }
                if (event.key.keysym.sym == SDLK_DOWN)
                {
                    scene->cam.x_r -= 0.1;
                }
                if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    scene->cam.y_r += 0.1;
                }
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    scene->cam.y_r -= 0.1;
                }
                if (event.key.keysym.sym == SDLK_KP_PLUS)
                {
                    vec = init_vec(0, 0, 1);
                    rotate(scene->cam, &vec.x, &vec.y, &vec.z);
                    scene->cam.orig = vec_sum(scene->cam.orig, vec);
                }
                if (event.key.keysym.sym == SDLK_KP_MINUS)
                {
                    vec = init_vec(0, 0, 1);
                    rotate(scene->cam, &vec.x, &vec.y, &vec.z);
                    scene->cam.orig = vec_sub(scene->cam.orig, vec);
                }
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    printf("%f\n", scene->r);
                    printf("%f %f %f\n", scene->cam.orig.x, scene->cam.orig.y, scene->cam.orig.z);
                }
                // printf("%d\n", event.key.keysym.sym);
                draw(scene, sdl);
                SDL_RenderPresent(sdl->render);
            }
                
        }
    }
}

void    init(t_sdl *sdl, t_scene *scene)
{
    scene->cam.orig = init_vec(0, 0, -100);
    scene->c.x = 0;
    scene->c.y = 0;
    scene->c.z = 5;
    scene->r = 25;
    scene->cam.dir = init_vec(0, 0, 1); // суммировать с векотором (0, 0 , 1)
    // scene->cam.dir = vec_norm(scene->cam.dir);
    scene->cam.x_r = scene->cam.dir.y;
    scene->cam.y_r = scene->cam.dir.x;
    scene->cam.z_r = 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    	exit(0); // change it
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &sdl->window, &sdl->render);
    SDL_RenderClear(sdl->render);
}

int main() {
    t_sdl sdl;
    t_scene scene;

    init(&sdl, &scene);
    loop(&sdl, &scene);
    SDL_DestroyWindow(sdl.window);
    SDL_Quit();
    return 0;
}