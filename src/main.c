/*
**	created by eflorean
*/

#include "SDL.h"
#include "../includes/RTv1.h"
#include <stdio.h> 

int main() {
    SDL_Surface* screen_surface;
    SDL_Window* window;
    SDL_Event event;
    int run;

    run = 1;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    	return (1);
    window = SDL_CreateWindow("RTv1",SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    screen_surface = SDL_GetWindowSurface(window);
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 125, 53, 40));
    SDL_UpdateWindowSurface(window);
    printf("%d\n", SDL_QUIT);
    while (run)
    {
        while (SDL_PollEvent(&event))
        {
            // printf("%d\n", event.type);
            if (event.type == SDL_QUIT || event.type == 768)
                run = 0;
            // printf("%d\n", event.type);
            // 768 - kill the session
        }
        // draw scene after we have time
        // scene->draw();
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}