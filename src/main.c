#include <SDL2\SDL.h>
#include <stdio.h>
#include "..\lib\funcs.h"

#define WIDTH 900
#define HEIGHT 600

#define FPS 60
#define TARGET_FRAME_TIME (1000/FPS)

int main(int argc, char* argv[]) {
    //printf("hello world");

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    SDL_Event event;

    SDL_Rect rect = {200,200,50,50};

    int lastFrameTime = 0;
    float deltaTime = 0;
    int frameDelay = 0;

    int game = 1;
    while (game == 1) {
        // check how long last frame took to complete, then delay to make up the rest of the tine before we start new frame
        frameDelay = TARGET_FRAME_TIME - (SDL_GetTicks() - lastFrameTime);
        if (0 < frameDelay && frameDelay <= TARGET_FRAME_TIME) {
            SDL_Delay(frameDelay);
        };

        // get length of last frame (roughly 1000/FPS) and then save new frames start time
        deltaTime = (SDL_GetTicks() - lastFrameTime) / 1000.0f;
        lastFrameTime = SDL_GetTicks();

        //clear screen
        SDL_FillRect(surface, NULL, 0x00000000);

        while(SDL_PollEvent(&event)){
            switch (event.type){
                case(SDL_QUIT):
                game=0;
                break;
            }
        };

        SDL_FillRect(surface, &rect, 0xffffffff);
        SDL_UpdateWindowSurface(window);
    };
    return 0;
};