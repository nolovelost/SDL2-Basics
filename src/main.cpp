#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#include "mandala.h"
#include "texture.h"

#define FPS 60

int main(int argc, char* args[])
{
    // Get Mandala
    Mandala* mandala = Mandala::Instance();

    // Create a texture surface
    LTexture* planetTex = new LTexture();
    LTexture* spaceBgTex = new LTexture();

    planetTex->LoadFromFile("./elements/images/background/parallax-space-big-planet.png");
    spaceBgTex->LoadFromFile("./elements/images/background/parallax-space-backgound.png");

    // Set the initial position of the planet
    float planetX = (WINDOW_WIDTH - planetTex->GetWidth()) / 2;
    float planetY = (WINDOW_HEIGHT - planetTex->GetHeight()) / 2;

    // << Game Loop >>
    bool exitState = false;
    SDL_Event event;
    while (!exitState)
    {
        // process events
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
                exitState = true;
            else if (event.type == SDL_KEYDOWN)
            {
                SDL_Keycode key = event.key.keysym.sym;
                if (key == SDLK_w)
                    planetY -= 25.0f;
                else if (key == SDLK_s)
                    planetY += 25.0f;
                if (key == SDLK_a)
                    planetX -= 25.0f;
                else if (key == SDLK_d)
                    planetX += 25.0f;
            }
        }

        // Game Code before render clear
        // ...

        // Clear the renderer window
        SDL_RenderClear(mandala->GetRenderer());

        // Game Code after render clear
        // ...

        // Set Main Viewport
        SDL_Rect primeViewport;
        primeViewport.h = WINDOW_HEIGHT;
        primeViewport.w = WINDOW_WIDTH * 0.75f;
        primeViewport.x = 0;
        primeViewport.y = 0;
        SDL_RenderSetViewport(mandala->GetRenderer(), &primeViewport);
        spaceBgTex->SetWidth(primeViewport.w);
        spaceBgTex->SetHeight(primeViewport.h);
        spaceBgTex->Render(0, 0);
        planetTex->Render(planetX, planetY);

        // Set Left Pane
        SDL_Rect leftViewport;
        leftViewport.h = WINDOW_HEIGHT;
        leftViewport.w = WINDOW_WIDTH - primeViewport.w;
        leftViewport.x = primeViewport.w;
        leftViewport.y = 0;
        SDL_RenderSetViewport(mandala->GetRenderer(), &leftViewport);
        planetTex->Render(0, 0);
        
        // Swap buffer
        SDL_RenderPresent(mandala->GetRenderer());

        // Set refresh rate
        SDL_Delay(1000/FPS);
    }
    
    planetTex->Free();
    spaceBgTex->Free();

    // QUIT Application
    mandala->DestroyMandala();
    return 0;
}
