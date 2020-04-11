/*
**	created by eflorean
*/

#include <parser_rtv1.h>
//#include "RTv1.h"

/*void loop(t_sdl *sdl, t_cam *scene)
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
            if (event.shape == SDL_QUIT)
                run = 0;
            if (event.shape == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    run = 0;
                if (event.key.keysym.sym == SDLK_d)
                    scene->cam.orig.x += 0.1;
                if (event.key.keysym.sym == SDLK_a)
                    scene->cam.orig.x -= 0.1;
                if (event.key.keysym.sym == SDLK_s)
                    scene->cam.orig.y -= 0.1;
                if (event.key.keysym.sym == SDLK_w)
                    scene->cam.orig.y += 0.1;
                if (event.key.keysym.sym == SDLK_UP)
                    scene->cam.orig.z += 0.1;
                if (event.key.keysym.sym == SDLK_DOWN)
                    scene->cam.orig.z -= 0.1;
                if (event.key.keysym.sym == SDLK_RIGHT)
                    scene->cam.dir.y += 0.1;
                if (event.key.keysym.sym == SDLK_LEFT)
                    scene->cam.dir.y -= 0.1;
                if (event.key.keysym.sym == SDLK_z)
                    scene->cam.x_r += 0.01;
                if (event.key.keysym.sym == SDLK_x)
                    scene->cam.y_r += 0.01;
                if (event.key.keysym.sym == SDLK_c)
                    scene->cam.z_r += 0.01;
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    // scene->r += 0.1;
                    printf("%f\n", scene->r);
                    printf("%f %f %f\n", scene->cam.orig.x, scene->cam.orig.y, scene->cam.orig.z);
                }
                // printf("%d\n", event.key.keysym.sym);
                draw(scene, sdl);
                SDL_RenderPresent(sdl->render);
            }
                
        }
        // draw scene after we have time
        // scene->draw();
    }
}

void    init(t_sdl *sdl, t_cam *scene)
{
    scene->cam.orig = init_vec(0, 0, 0);
    scene->c.x = 0;
    scene->c.y = 0;
    scene->c.z = 5;
    scene->r = 2;
    scene->cam.dir = init_vec(0, 0, 1);
    scene->cam.x_r = 0;
    scene->cam.y_r = 0;
    scene->cam.z_r = 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    	exit(0); // change it
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &sdl->window, &sdl->render);
    SDL_RenderClear(sdl->render);
}*/

int main(int argc, char **argv) {
   /* t_sdl sdl;
    t_cam scene;

    init(&sdl, &scene);
    loop(&sdl, &scene);
    SDL_DestroyWindow(sdl.window);
    SDL_Quit();*/
   	t_base scene;

   	scene.n_lt = 0;
   	scene.n_obj = 0;
   	scene.file = argv[1];
	parser(&scene);
    return 0;
}