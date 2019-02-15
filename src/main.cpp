#include <stdio.h>
#include <string>

#ifndef  _MANDALA_H_
#include "mandala.h"
#endif

#include "TestMachinery.h"


int main(int argc, char* args[])
{
    // Get Mandala
    Mandala* mandala = Mandala::Instance();
    // Create a new Machine
    Machine* machine = new TestMachinery();

    // << Game Loop >>
    bool exitState = false;
    SDL_Event event;
    while (!exitState)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
                exitState = true;
            
            machine = machine->HandleEvent(event);
            if (!machine)
                break;
        }
        
        // Update Machine
        machine = machine->Update(NULL);
        if (!machine)
                break;

        // Render Machine
        machine->Render();
    }

    // QUIT Application
    mandala->DestroyMandala();
    return 0;
}
