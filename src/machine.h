#ifndef  _MANDALA_H_
#include "mandala.h"
#endif

#include "input.h"
#include "texture.h"

class Machine
{
public:
    int Start();
    int Update();
    int End();

private:
    Mandala* mandala;
    Input* input;

    // test attributes
    Texture *planetTex;
    Texture *spaceBgTex;
    float planetX;
    float planetY;
};