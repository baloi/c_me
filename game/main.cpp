#include <iostream>
#include <SDL2/SDL.h>
//#include "res_path.h"

int main(int argc, char *args[])
{

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 0;
    }

    SDL_Window *win = SDL_CreateWindow("SDL!!", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
    if (win == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_DestroyWindow(win);
    SDL_Quit();


    return 0;
}
