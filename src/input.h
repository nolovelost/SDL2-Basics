#include <SDL2/SDL.h>
#include <map>

class Input
{

public:
    void ClearHistory();
    void ProcessKeyUp(const SDL_Event& event);
    void ProcessKeyDown(const SDL_Event& event);
    bool IsKeyPressed(SDL_Scancode key);
    bool IsKeyReleased(SDL_Scancode key);
    bool IsKeyHeld(SDL_Scancode key);

protected:
    std::map<SDL_Scancode, bool> pressedKeys;
    std::map<SDL_Scancode, bool> releasedKeys;
    std::map<SDL_Scancode, bool> heldKeys;

};