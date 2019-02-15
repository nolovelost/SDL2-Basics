#include "input.h"

#ifdef __USE_INPUT_EVENT__
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
}

void Input::ProcessKeyUp(const SDL_Event& event)
{
    pressedKeys[event.key.keysym.scancode] = false;
    releasedKeys[event.key.keysym.scancode] = true;
}

void Input::ProcessMouseButtonDown(const SDL_Event& event)
{
    pressedMouseButtons[event.button.button] = true;
    releasedMouseButtons[event.button.button] = false;
}

void Input::ProcessMouseButtonUp(const SDL_Event& event)
{
    pressedMouseButtons[event.button.button] = false;
    releasedMouseButtons[event.button.button] = true;
}

void Input::ProcessMouseMotion(const SDL_Event& event)
{
    mouseMoving = !(mousePosition.x == event.motion.x && mousePosition.x == event.motion.y);
    mousePosition.x = event.motion.x;
    mousePosition.y = event.motion.y;
    mouseRelativePostion.x = event.motion.xrel;
    mouseRelativePostion.y = event.motion.yrel;
}

bool Input::IsKeyPressedEvent(SDL_Scancode key)
{
    return pressedKeys[key];
}

bool Input::IsKeyReleasedEvent(SDL_Scancode key)
{
    return releasedKeys[key];
}

bool Input::IsMouseButtonPressedEvent(Uint8 button)
{
    return pressedMouseButtons[button];
}

bool Input::IsMouseButtonReleasedEvent(Uint8 button)
{
    return releasedMouseButtons[button];
}

bool Input::IsMouseMovingEvent()
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

int Input::GetRelativeMouseX()
{
    return mouseRelativePostion.x;
}

int Input::GetRelativeMouseY()
{
    return mouseRelativePostion.y;
}
#endif


#ifdef __USE_INPUT_STATE__
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
#endif