#include <iostream>
#include <SDL2/SDL.h>


// Notes:
// load image from file and display it on the screen

//Tip : avoid using global variables (unnecesary)
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool loadMedia(SDL_Surface*& image_HelloWorld)
{
    bool success = true;
    image_HelloWorld = SDL_LoadBMP("resources/monochrome_hw.bmp");
    if (image_HelloWorld == nullptr)
    {
        std::cerr << "Unable to load image! SDL Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    return success;
}

int main(int argc, char* args[])
{
    // Tip:  
    // Always remember to initialize your pointers. We set them to NULL immediately when declaring them.
    SDL_Window *window = nullptr;
    SDL_Surface *screenSurface = nullptr;
    
    // Tip: 
    // SDL surface is just an image data type that contains the pixels of an image
    // along with all data needed to render it
    SDL_Surface *image_HelloWorld = nullptr;

    // Tip: 
    // Notice that these are pointers to SDL surfaces. The reason is that 1) we'll be dynamically 
    // allocating memory to load images and 2) it's better to reference an image by memory location. 
    // Imagine you had a game with a brick wall that consisted of the same brick image being rendered 
    // multiple times (like Super Mario Bros). It's wasteful to have dozens of copies of the image in 
    // memory when you can have one copy of the image and render it over and over again.
    
    //SDL_Surface *image_HelloWorld = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    
    // create windows
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    // validate windows
    if (window == nullptr)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // create surface
    screenSurface = SDL_GetWindowSurface(window);

    // load image
    if (!loadMedia(image_HelloWorld))
    //if (!loadMedia())
    {
        std::cerr << "Failed to load media!" << std::endl;
        SDL_Log("Failed to load media!\n");
        return 1;
    }

    // apply image
    SDL_BlitSurface(image_HelloWorld, NULL, screenSurface, NULL);
    // update surface
    SDL_UpdateWindowSurface(window);

    // wait until the user closes the window
    bool quit = false;
    SDL_Event e;
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

    //free resources
    SDL_DestroyWindow(window);    
    SDL_FreeSurface(screenSurface);    
    SDL_FreeSurface(image_HelloWorld);
    SDL_Quit();
    return 0;
}