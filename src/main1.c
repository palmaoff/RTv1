/*
**	created by eflorean
*/

#include <parser_rtv1.h>
//#include "RTv1.h"
#include <SDL2/SDL.h>

const int SDL_SCREEN_WIDTH = 640;
const int SDL_SCREEN_HEIGHT = 480;

int	sdl_quit(t_sdl *sdl)
{
	SDL_FreeSurface(sdl->smile);
	sdl->smile = NULL;
	SDL_DestroyWindow(sdl->win);
	SDL_Quit();
}

int sdl_load(t_sdl *sdl)
{
	sdl->smile = SDL_LoadBMP("Ricardo2.bmp");

	if(sdl->smile == NULL)
		return (1);
	return (0);
}

int sdl_init(t_sdl *sdl)
{
	if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
		return 1;
	sdl->win = SDL_CreateWindow("Hello, SDL 2!",SDL_WINDOWPOS_UNDEFINED,
							  SDL_WINDOWPOS_UNDEFINED, SDL_SCREEN_WIDTH, SDL_SCREEN_HEIGHT,
							  SDL_WINDOW_SHOWN);
	if (sdl->win == NULL)
		return 1;
	sdl->scr = SDL_GetWindowSurface(sdl->win);
	return(0);
}

int main(int argc, char **argv) {
   	t_base scene;
   	t_sdl sdl;

   	scene.n_lt = 0;
   	scene.n_obj = 0;
   	scene.file = argv[1];
	parser(&scene);
	if(sdl_init(&sdl) == 1)
		return (1);
	if(sdl_load(&sdl))
		return 1;
	SDL_BlitSurface(sdl.smile, NULL, sdl.scr, NULL);
	SDL_UpdateWindowSurface(sdl.win);
	SDL_Delay(3000);
	sdl_quit(&sdl);
	return(0);
}