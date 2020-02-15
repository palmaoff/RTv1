/*
**	created by eflorean
*/

#include "RTv1.h"

void loop(void)
{
    SDL_Event event;
    int run;

    run = 1;
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

void    init(t_sdl *sdl)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    	exit(0); // change it 
    SDL_CreateWindowAndRenderer(WIDTH, WIDTH, 0, &sdl->window, &sdl->render);

    SDL_RenderClear(sdl->render);
}

int main() {
    t_sdl sdl;

    init(&sdl);
    SDL_SetRenderDrawColor(sdl.render, 125, 53, 40, 1);
    SDL_RenderDrawLine(sdl.render, 320, 200, 300, 240);
    SDL_RenderDrawLine(sdl.render, 300, 240, 340, 240);
    SDL_RenderDrawLine(sdl.render, 340, 240, 320, 200);
    SDL_RenderPresent(sdl.render);

    loop();
    SDL_DestroyWindow(sdl.window);
    SDL_Quit();
    return 0;
}