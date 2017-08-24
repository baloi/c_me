// http://www.willusher.io/pages/sdl2/
#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>
#include <ctime>
#include <iostream>

#define S_WIDTH 1024
#define S_HEIGHT 786

void drawCircle(SDL_Renderer *renderer, float radius, float center_x=S_WIDTH/2,         float center_y=S_HEIGHT/2)
{
    int x, y;
    for(int i=0; i<=360; i=i+1) {
        x = center_x + radius*cos(i*M_PI/180);
        y = center_y + radius*sin(i*M_PI/180);
        SDL_RenderDrawPoint(renderer, x, y);
    }

}

void drawLine(SDL_Renderer *renderer, float distance, float angle_in_degrees,
        float center_x=S_WIDTH/2, float center_y=S_HEIGHT/2)
{
    int x, y;
    y = center_y + distance * sin(angle_in_degrees*3.14/180);
    x = center_x + distance * cos(angle_in_degrees*3.14/180);
    SDL_RenderDrawLine(renderer, S_WIDTH/2, S_HEIGHT/2, x, y);
}

class Graphics 
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    //@@TODO: rgba forecolor;
public:
    //SDL_Event event;
    Graphics() {
        SDL_CreateWindowAndRenderer(S_WIDTH, S_HEIGHT, 0, &window, &renderer);
        //@TODO: forecolor = rgba(255, 255, 255, 255);
        //SDL_Window *win = SDL_CreateWindow("Hello World", 100, 100, 640, 480, 
        //SDL_WINDOW_SHOWN);

    }

    ~Graphics() {
        SDL_Quit();
    }
};

int main(int argc, char **argv)
{

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 0;
    }

    //SDL_Window *win = SDL_CreateWindow("Hello World", 100, 100, 640, 480, 
    //    SDL_WINDOW_SHOWN);
    //if (win == nullptr) {
    //    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    //    SDL_Quit();
    //    return 1;
    //}

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    SDL_CreateWindowAndRenderer(S_WIDTH, S_HEIGHT, 0, &window, &renderer);

    //SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED |
    //        SDL_RENDERER_PRESENTVSYNC);
    //if (ren == nullptr) {
    //    SDL_DestroyWindow(win);
    //    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() 
    //            << std::endl;
    //    SDL_Quit();
    //    return 1;
    //}

/*
    std::string imagePath = getResourcePath("Lesson1") + "mad_tux.bmp";
    SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
    if (bmp == nullptr) {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    if (tex == nullptr) {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError()
                << std::endl;
        SDL_Quit();
        return 1;
    }

*/
    //SDL_RenderClear(ren);
    //SDL_RenderCopy(ren, tex, NULL, NULL);
    //SDL_RenderPresent(ren);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 55);

    SDL_RenderFillRect(renderer, NULL);
    SDL_RenderPresent(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    drawCircle(renderer, 160);
    SDL_RenderPresent(renderer);

    SDL_Delay(2000);

    while (true) {
        time_t rawtime;
        struct tm * timeinfo;
        time(&rawtime);
        timeinfo = localtime (&rawtime);

        int hr = timeinfo->tm_hour;
        int min = timeinfo->tm_min;
        int sec = timeinfo->tm_sec;

        hr = (hr>=12) ? (hr-12) : hr;

        //std::cout<<min;

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        drawCircle(renderer, 160);
        SDL_RenderPresent(renderer);

        drawLine(renderer, 150, (-90 + sec*6));
        drawLine(renderer, 100, (-90 + min*6));
        drawLine(renderer, 50, (-90 + hr*360/12));
        SDL_RenderPresent(renderer);

        SDL_PollEvent(&event);

        if (event.type == SDL_QUIT) break;
        if (event.type == SDL_KEYUP && 
                event.key.keysym.sym == SDLK_ESCAPE) break;
    }

    // Cleaning up
    //SDL_DestroyTexture(tex);
    //SDL_DestroyRenderer(ren);
    //SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
