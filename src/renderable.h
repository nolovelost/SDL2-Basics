#ifndef _SDL_H_
#define _SDL_H_
#include <SDL2/SDL.h>
#endif


class Renderable
{
protected:
    SDL_Surface* surface;
    SDL_Texture* texture;   // Increament pointers using sizeof() for multiple textures

    virtual ~Renderable()
    {
        if (surface != NULL)
        {
            SDL_FreeSurface(surface);
            surface = NULL;
        }
        if (texture != NULL)
        {
            SDL_DestroyTexture(texture);
            texture = NULL;
        }
    }

  public:
    int x, y, width, height;     // X position, Y position, Width, Height

    SDL_Texture *GetTexture() { return texture; }
    SDL_Surface *GetSurface() { return surface; }
    
    virtual SDL_Surface *LoadSurface(void) = 0;
    virtual SDL_Texture *LoadTexture(SDL_Surface *texSurface) = 0;
    virtual void Free() = 0;
    virtual void Render(int x, 
        int y, 
        SDL_Rect* clip = NULL, 
        double angle = 0.0, 
        SDL_Point* center = NULL, 
        SDL_RendererFlip flip = SDL_FLIP_NONE) = 0;
};