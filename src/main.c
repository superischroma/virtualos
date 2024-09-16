#include "../include/vos.h"
#include "../include/log.h"

#define SDL_MAIN_HANDLED
#define SCREEN_X 960
#define SCREEN_Y 720

#include <SDL2/SDL.h>

char* PROGRAM_NAME;

int main_finalize(int r, uint8_t* mem, SDL_Window* window, bool init)
{
    free(mem);
    SDL_DestroyWindow(window);
    if (init)
        SDL_Quit();
    return r;
}

int main(int argc, char** argv)
{
    PROGRAM_NAME = argv[0];

    SDL_Window* window = NULL;
    SDL_Surface* surface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        errorf("Failed to initialize SDL\n");
        return main_finalize(EXIT_FAILURE, NULL, window, false);
    }

    window = SDL_CreateWindow("virtualos", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_X, SCREEN_Y, 0);

    if (!window)
    {
        errorf("Failed to create window\n");
        return main_finalize(EXIT_FAILURE, NULL, window, true);
    }

    surface = SDL_GetWindowSurface(window);

    vos_t vos;
    vos.mem = calloc(MEMORY_SIZE, sizeof(uint8_t));

    for (SDL_Event e;;)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                goto quit;
        }
        SDL_UpdateWindowSurface(window);
    }
    quit:

    return main_finalize(EXIT_SUCCESS, vos.mem, window, true);
}