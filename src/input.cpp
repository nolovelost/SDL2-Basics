#include "input.h"

void Input::ClearHistory()
{
    pressedKeys.clear();
    releasedKeys.clear();
}

void Input::ProcessKeyDown(const SDL_Event& event)
{
    pressedKeys[event.key.keysym.scancode] = true;
    releasedKeys[event.key.keysym.scancode] = false;
    heldKeys[event.key.keysym.scancode] = true;
}

void Input::ProcessKeyUp(const SDL_Event& event)
{
    pressedKeys[event.key.keysym.scancode] = false;
    releasedKeys[event.key.keysym.scancode] = true;
    heldKeys[event.key.keysym.scancode] = false;
}

bool Input::IsKeyPressed(SDL_Scancode key)
{
    return pressedKeys[key];
}

bool Input::IsKeyReleased(SDL_Scancode key)
{
    return releasedKeys[key];
}

bool Input::IsKeyHeld(SDL_Scancode key)
{
    return heldKeys[key];
}