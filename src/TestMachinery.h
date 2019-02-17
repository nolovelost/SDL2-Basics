#include "machine.h"

#include "input.h"
#include "sprite.h"

class TestMachinery : public Machine
{
public:
    TestMachinery();
    ~TestMachinery();
    Machine* Update(double deltaTime) override;
    Machine* HandleEvent(const SDL_Event& event) override;
    void Render() override;

private:
    Mandala* mandala;
    Input* input;

    Sprite *planetTex;
    Sprite *spaceBgTex;
    float planetX;
    float planetY;
};