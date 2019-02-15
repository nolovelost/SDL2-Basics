#include <stdio.h>
#include <string>
#include "mandala.h"
#include "machine.h"

int main(int argc, char* args[])
{
    // Get Mandala
    Mandala* mandala = Mandala::Instance();
    // Create a new Machine
    Machine* machine = new Machine();

    // Rev up the Machine
    machine->Start();
    
    // << Game Loop >>
    bool exitState = false;
    SDL_Event event;
    while (!exitState)
    {
        exitState = machine->Update();
    }

    // QUIT Application
    machine->End();
    mandala->DestroyMandala();
    return 0;
}
