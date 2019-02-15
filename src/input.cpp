#include "input.h"

void Input::ClearHistory()
{
    pressedKeys.clear();
    releasedKeys.clear();
    pressedMouseButtons.clear();
    releasedMouseButtons.clear();
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

void Input::ProcessMouseButtonDown(const SDL_Event& event)
{
    pressedMouseButtons[event.button.button] = true;
    releasedMouseButtons[event.button.button] = false;
    heldMouseButtons[event.button.button] = true;
}

void Input::ProcessMouseButtonUp(const SDL_Event& event)
{
    pressedMouseButtons[event.button.button] = false;
    releasedMouseButtons[event.button.button] = true;
    heldMouseButtons[event.button.button] = false;
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

bool Input::IsMouseButtonPressed(Uint8 button)
{
    return pressedMouseButtons[button];
}

bool Input::IsMouseButtonReleased(Uint8 button)
{
    return releasedMouseButtons[button];
}

bool Input::IsMouseButtonHeld(Uint8 button)
{
    return heldMouseButtons[button];
}