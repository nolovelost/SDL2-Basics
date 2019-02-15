#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#include "mandala.h"
#include "input.h"
#include "texture.h"

#define FPS 60

int main(int argc, char* args[])
{
    // Get Mandala
    Mandala* mandala = Mandala::Instance();

    // Create Input
    Input* input = new Input();

    // Create a texture surface
    Texture* planetTex = new Texture();
    Texture* spaceBgTex = new Texture();

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
        }

        // Update Input States!
        input->UpdateKeyboardStates();
        input->UpdateMouseStates();

        // Game Code before render clear
        // ...
        if (input->IsKeyPressed(SDL_SCANCODE_W))
            planetY -= 5.0f;
        if (input->IsKeyPressed(SDL_SCANCODE_S))
            planetY += 5.0f;
        if (input->IsKeyPressed(SDL_SCANCODE_A))
            planetX -= 5.0f;
        if (input->IsKeyPressed(SDL_SCANCODE_D))
            planetX += 5.0f;
        if (input->IsMouseButtonPressed(SDL_BUTTON_LEFT))
        {
            planetX = WINDOW_WIDTH/2;
            planetY = WINDOW_HEIGHT/2;
        }
        if (input->IsMouseMoving())
        {
            planetX = input->GetMouseX();
            planetY = input->GetMouseY();
        }

        // Clear the renderer window
        SDL_RenderClear(mandala->GetRenderer());

        // Game Code after render clear
        // ...

        // Render Main Viewport
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

        // Render Right Pane
        SDL_Rect rightViewport;
        rightViewport.h = WINDOW_HEIGHT;
        rightViewport.w = WINDOW_WIDTH - primeViewport.w;
        rightViewport.x = primeViewport.w;
        rightViewport.y = 0;
        SDL_RenderSetViewport(mandala->GetRenderer(), &rightViewport);
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
