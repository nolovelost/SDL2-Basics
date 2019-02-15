#ifndef  _MANDALA_H_
#include "mandala.h"
#endif

class Machine
{
public:
    virtual Machine* Update(double deltaTime) = 0;
    // #TODO: Need to create a custom event system
    // virtual Machine* HandleEvent(const GameEvent& event) = 0;
    virtual Machine* HandleEvent(const SDL_Event& event) = 0;
    virtual void Render() = 0;
};