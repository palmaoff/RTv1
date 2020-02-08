/*
**	created by eflorean
*/

#include "SDL.h"
#include "../includes/RTv1.h"
#include <stdio.h> 

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

int main() {
    SDL_Surface* screen_surface;
    SDL_Window* window;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    	return (1);
    window = SDL_CreateWindow("RTv1",SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    screen_surface = SDL_GetWindowSurface(window);
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 125, 53, 40));
    SDL_UpdateWindowSurface(window);
    // printf("%d\n", SDLK_ESCAPE);
    loop();
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}