#include "mandala.h"

Mandala* Mandala::mandala = NULL;

bool Mandala::Init()
{
    // Init video module
    bool successInit = SDL_Init(SDL_INIT_VIDEO);

    if (successInit)
    {
        printf("Error initializing SDL: %s ", SDL_GetError());
        return 1;
    }

    // Init is successful
    printf("SDL Initialization successful.\n");

    // Init window and get Screen Surface
    window = SDL_CreateWindow("SDL-test-program",  /// window title 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,     /// window position
        windowWidth, windowHeight,                        /// window size
        0);                                                 /// flags 

    // Window init error
    if (window == 0)
    {
        printf("Error initializing SDL_Window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    else
    {
        // Gather the main window surface
        screenSurface = SDL_GetWindowSurface(window);
    }

    // Window initialization successful
    printf("SDL_Window initialization successful.\n");

    // Init the renderer hardware
    Uint32 rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    renderer = SDL_CreateRenderer(window, -1, rendererFlags);
    if (!renderer)
    {
        printf("Error initializing SDL_Renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Renderer initialization successful
    printf("SDL_Renderer initialization successful.\n");

    // Initialization successful
    return 0;
}

void Mandala::End()
{
    // Clean Exit
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;
    screenSurface = NULL;
    
    mandala = NULL;

    IMG_Quit();
    SDL_Quit();
}

