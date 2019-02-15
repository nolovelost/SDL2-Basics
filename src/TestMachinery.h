#include "machine.h"

#include "input.h"
#include "texture.h"

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

    Texture *planetTex;
    Texture *spaceBgTex;
    float planetX;
    float planetY;
};