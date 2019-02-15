#include <SDL2/SDL.h>
#include <map>

//#define __USE_INPUT_EVENT__
#define __USE_INPUT_STATE__

class Input
{
    
#ifdef __USE_INPUT_EVENT__
public:
    void ClearHistory();
    
    void ProcessKeyUp(const SDL_Event& event);
    void ProcessKeyDown(const SDL_Event& event);
    void ProcessMouseButtonUp(const SDL_Event& event);
    void ProcessMouseButtonDown(const SDL_Event& event);
    void ProcessMouseMotion(const SDL_Event& event);
    
    // Keyboard Key Queries
    bool IsKeyPressedEvent(SDL_Scancode key);
    bool IsKeyReleasedEvent(SDL_Scancode key);
    // Mouse Button Queries
    bool IsMouseButtonPressedEvent(Uint32 button);
    bool IsMouseButtonReleasedEvent(Uint32 button);
    int GetRelativeMouseX();
    int GetRelativeMouseY();
protected:
    // Keyboard Keys
    std::map<SDL_Scancode, bool> pressedKeys;
    std::map<SDL_Scancode, bool> releasedKeys;
    // Mouse Buttons
    std::map<Uint8, bool> pressedMouseButtons;
    std::map<Uint8, bool> releasedMouseButtons;
    SDL_Point mouseRelativePostion;

#endif

public:
    void UpdateKeyboardStates();
    void UpdateMouseStates();

    // Keyboard Key Queries
    bool IsKeyPressed(SDL_Scancode key);
    bool IsKeyReleased(SDL_Scancode key);
    // Mouse Button Queries
    bool IsMouseButtonPressed(Uint32 button);
    bool IsMouseButtonReleased(Uint32 button);
    // Mouse Position Query
    bool IsMouseMoving();
    int GetMouseX();
    int GetMouseY();

protected:
    // Keyboard Keys
    const Uint8* keyStates;
    // Mouse Buttons
    Uint32 mouseStates;
    // Mouse Motion
    bool mouseMoving;
    SDL_Point mousePosition;
    SDL_Point prevMousePosition;
};