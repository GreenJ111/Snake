#include <SDL2\SDL.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 600

int main(int argc, char* argv[]) {
    //printf("hello world");

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {200,200,50,50};
    SDL_Event event;

    int game = 1;
    while (game == 1) {
        SDL_FillRect(surface, NULL, 0x00000000);

        while(SDL_PollEvent(&event)){
            switch (event.type){
                case(SDL_QUIT):
                game=0;
                break;
            }
        
            SDL_FillRect(surface, &rect, 0xffffffff);
            SDL_UpdateWindowSurface(window);
        };
    };
    return 0;
};