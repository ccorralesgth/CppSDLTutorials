#include <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *args[])
{
    // the window we'll be rendering to
    SDL_Window *window = nullptr;

    // the surface contained by the window
    SDL_Surface *screenSurface = nullptr;

    // Init
    // if (!SDL_Init(SDL_INIT_VIDEO))
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    else
    {
        // create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        }

        // get windows surface
        screenSurface = SDL_GetWindowSurface(window);
        if (screenSurface == nullptr)
        {
            std::cerr << "Surface could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        }

        // fill the surface white
        SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
        
        // update the surface
        SDL_UpdateWindowSurface(window);

        // keep windows up until quit
        SDL_Event e;
        bool quit = false;
        while (!quit)
        {
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
            }
        }
    }
    // destroy window
    SDL_DestroyWindow(window);
    // quit SDL
    SDL_Quit();
    return 0;
}