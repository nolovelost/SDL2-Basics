#include "input.h"

void Input::UpdateKeyboardStates()
{
    keyStates = SDL_GetKeyboardState(NULL);
}

void Input::UpdateMouseStates()
{
    mouseStates = SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
    mouseMoving = !(mousePosition.x == prevMousePosition.x && mousePosition.y == prevMousePosition.y);
    prevMousePosition = mousePosition;
}

bool Input::IsKeyPressed(SDL_Scancode key)
{
    return keyStates[key];
}

bool Input::IsKeyReleased(SDL_Scancode key)
{
    return !keyStates[key];
}

bool Input::IsMouseButtonPressed(Uint32 button)
{
    return mouseStates & SDL_BUTTON(button);
}

bool Input::IsMouseButtonReleased(Uint32 button)
{
    return !(mouseStates & SDL_BUTTON(button));
}

bool Input::IsMouseMoving()
{
    return mouseMoving;
}

int Input::GetMouseX()
{
    return mousePosition.x;
}

int Input::GetMouseY()
{
    return mousePosition.y;
}