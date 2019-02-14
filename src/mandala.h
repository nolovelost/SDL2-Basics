#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Mandala
{

// << B E G I N >> //

private:
    static Mandala* mandala;
    Mandala(int winWidth = WINDOW_WIDTH, int winHeight = WINDOW_HEIGHT) : windowWidth(winWidth), windowHeight(winHeight) { Init(); }
    Mandala(Mandala* param){ if (mandala == NULL) mandala = param; }
    Mandala& operator=(const Mandala&);

protected:
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;
    SDL_Renderer *renderer = NULL;

    bool Init();
    void End();

    int windowWidth;
    int windowHeight;

public:
    static Mandala *Instance()
    {
        if (mandala == NULL)
            mandala = new Mandala();
        return mandala;
    }

    SDL_Window* GetWindow(){return window;}
    SDL_Surface* GetScreenSurface(){return screenSurface;}
    SDL_Renderer* GetRenderer(){return renderer;}

    static void DestroyMandala()
    {
        if (mandala == NULL)
            return;
        else
            mandala->End();
    }
};