#include <iostream>
#include <SDL2/SDL.h>

//Notes: 
// This file is about event handling

const int SCREEN_WIDTH = 640;   
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]){
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Get window surface
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

    // Fill the surface white
    SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    // Update the surface
    SDL_UpdateWindowSurface(window);

    // main loop  flag
    bool quit = false;

    //event handler
    SDL_Event e;
    while(!quit){
        // handle events on queue
        while(SDL_PollEvent(&e) != 0){
            // user quit when closing window
            if(e.type == SDL_QUIT){
                quit = true;
            }
            // user quit when pressing escape
            if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE){
                quit = true;
            }
            // user quit when pressing q
            if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q){
                quit = true;
            }
            // user quit when pressing double click
            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.clicks == 2){
                quit = true;
            }
        }
    }

    // Destroy window
    SDL_DestroyWindow(window);
    SDL_FreeSurface(screenSurface);
    // Quit SDL
    SDL_Quit();
    return 0;
}