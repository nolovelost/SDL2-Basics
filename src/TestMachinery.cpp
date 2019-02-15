#include "TestMachinery.h"

#define FPS 60

TestMachinery::TestMachinery()
{
    mandala = Mandala::Instance();
    input = new Input();

    // Test Procedures
    planetTex = new Texture();
    spaceBgTex = new Texture();
    planetTex->LoadFromFile("./elements/images/background/parallax-space-big-planet.png");
    spaceBgTex->LoadFromFile("./elements/images/background/parallax-space-backgound.png");
    planetX = (WINDOW_WIDTH - planetTex->GetWidth()) / 2;
    planetY = (WINDOW_HEIGHT - planetTex->GetHeight()) / 2;
}

Machine* TestMachinery::HandleEvent(const SDL_Event& event)
{
    // Update Input States
    input->UpdateKeyboardStates();
    input->UpdateMouseStates();

    return this;
}

Machine* TestMachinery::Update(double deltaTime)
{
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
    if (input->IsMouseButtonPressed(SDL_BUTTON_RIGHT))
        return nullptr;

    return this;
}

void TestMachinery::Render()
{
    // Clear the renderer window
    SDL_RenderClear(mandala->GetRenderer());

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

TestMachinery::~TestMachinery()
{
    planetTex->Free();
    spaceBgTex->Free();
}