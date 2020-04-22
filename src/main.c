/*
**	created by eflorean
*/

#include "parser_rtv1.h"
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
                    rotate(scene->cam, &vec);
                    scene->cam.orig = vec_sum(scene->cam.orig, vec);
                }
                if (event.key.keysym.sym == 45)
                {
                    vec = init_vec(0, 0, 1);
                    rotate(scene->cam, &vec);
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

void    init(t_sdl *sdl, t_scene *scene, t_base *base)
{
    // CAMERA
//    scene->cam.orig = init_vec(0, 0, 0);
//    scene->cam.dir = init_vec(0, 0, 1); // суммировать с векотором (0, 0 , 1)
    scene->cam.orig = base->cam.orig;
    scene->cam.dir = base->cam.dir; // суммировать с векотором (0, 0 , 1)
    scene->cam.dir = vec_norm(scene->cam.dir);
    scene->cam.x_r = scene->cam.dir.y;
    scene->cam.y_r = scene->cam.dir.x;
    scene->cam.z_r = 0;

    // LIGHT
//    scene->light[0].p = init_vec(50, 50, 50);
//    scene->light[1].p = init_vec(50, 50, -50);
    scene->light[0].p = base->lights[0].pos;
    scene->light[1].p = base->lights[1].pos;
//    scene->light[0].inst = 0.3;
//    scene->light[1].inst = 0.3;
    scene->light[0].inst = base->lights[0].size;
    scene->light[1].inst = base->lights[1].size;
    scene->ld = init_vec(1, 4, -3);
    scene->ld = vec_norm(scene->ld);

    // SPHERE
    scene->fig[0].type = 0;
//    scene->fig[0].c = init_vec(0, 0, 10);
//    scene->fig[0].k = 4;
//    scene->fig[0].color = init_color(10, 200, 180);
    scene->fig[0].c = base->obj[0].pos;
    scene->fig[0].k = base->obj[0].size;
    scene->fig[0].color = base->obj[0].color;
    scene->f_inter[0] = IntersectSphere;
    scene->f_norm[0] = sphere_norm;

    // PLANE
    scene->fig[1].type = 1;
//    scene->fig[1].c = init_vec(0, -10, 0);
//    scene->fig[1].v = init_vec(0,1,0);
//    scene->fig[1].color = init_color(100, 150, 50);
    scene->fig[1].c = base->obj[1].pos;
    scene->fig[1].v = base->obj[1].dir;
    scene->fig[1].color = base->obj[1].color;
    scene->f_inter[1] = IntersectPlane;
    scene->f_norm[1] = plane_norm;

    // CYLINDER
    scene->fig[2].type = 2;
//    scene->fig[2].c = init_vec(-10, 0, 20);
//    scene->fig[2].v = init_vec(1, -1, 0);
    scene->fig[2].c = base->obj[2].pos;
    scene->fig[2].v = base->obj[2].dir;
    scene->fig[2].v = vec_norm(scene->fig[2].v);
//    scene->fig[2].k = 5;
//    scene->fig[2].color = init_color(100, 200, 100);
    scene->fig[2].k = base->obj[2].size;
    scene->fig[2].color = base->obj[2].color;
    scene->f_inter[2] = IntersectCylinder;
    scene->f_norm[2] = cylinder_norm;

    // CONE
    scene->fig[3].type = 3;
//    scene->fig[3].c = init_vec(10, 0, 40);
//    scene->fig[3].v = init_vec(1, -1, 0);
    scene->fig[3].c = base->obj[3].pos;
    scene->fig[3].v = base->obj[3].dir;
    scene->fig[3].v = vec_norm(scene->fig[3].v);
//    scene->fig[3].k = 0.3;
//    scene->fig[3].color = init_color(100, 150, 0);
    scene->fig[3].k = base->obj[3].size;
    scene->fig[3].color = base->obj[3].color;
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
    t_base	base;

    base.file = av[1];
    base.n_lt = 0;
    base.n_lt = 0;
    parser(&base);
    init(&sdl, &scene, &base);
    loop(&sdl, &scene);
    SDL_DestroyWindow(sdl.window);
    SDL_Quit();
    return (0);
}