#include <SDL2/SDL.h>
#include <map>

class Input
{

public:
    void ClearHistory();
    
    void ProcessKeyUp(const SDL_Event& event);
    void ProcessKeyDown(const SDL_Event& event);
    void ProcessMouseButtonUp(const SDL_Event& event);
    void ProcessMouseButtonDown(const SDL_Event& event);

    // Keyboard Key Queries
    bool IsKeyPressed(SDL_Scancode key);
    bool IsKeyReleased(SDL_Scancode key);
    bool IsKeyHeld(SDL_Scancode key);
    // Mouse Button Queries
    bool IsMouseButtonPressed(Uint8 button);
    bool IsMouseButtonReleased(Uint8 button);
    bool IsMouseButtonHeld(Uint8 button);

protected:
    // Keyboard Keys
    std::map<SDL_Scancode, bool> pressedKeys;
    std::map<SDL_Scancode, bool> releasedKeys;
    std::map<SDL_Scancode, bool> heldKeys;
    // Mouse Buttons
    std::map<Uint8, bool> pressedMouseButtons;
    std::map<Uint8, bool> releasedMouseButtons;
    std::map<Uint8, bool> heldMouseButtons;

};