/*
**	created by eflorean
*/

#include "RTv1.h"

void loop(t_sdl *sdl, t_scene *scene)
{
    SDL_Event event;
    int run;


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
                // printf("%d\n", event.key.keysym.sym);
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    run = 0;
        }
        // draw scene after we have time
        // scene->draw();
    }
}

void    init(t_sdl *sdl, t_scene *scene)
{
    scene->o = init_vec(0, 0, 0);
    scene->dirO = init_vec(0, 0, 0);
    scene->c.x = 0;
    scene->c.y = 0;
    scene->c.z = 5;
    scene->r = 2;
    // SDL_Init — в случае неудачи всегда возвращается отрицательное число
	// SDL_GetError() всегда вернет текст проблемы.
    scene->cam.dir = init_vec(1, 0, 1);
    scene->cam.dir = normalize(scene->cam.dir);
    scene->cam.x_r = 0;
    scene->cam.y_r = 0;
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