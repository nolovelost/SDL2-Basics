#include <string>

#ifndef _SDL_H_
#define _SDL_H_
#include <SDL2/SDL.h>
#endif

#include "renderable.h"

//Texture wrapper class
class Sprite : public Renderable
{
public:
	Sprite();
	~Sprite();

	// Loads image at specified path
	bool LoadFromFile(std::string path);
	// Deallocates texture
	void Free() override;
	// Set color modulation
	void SetColor(Uint8 red, Uint8 green, Uint8 blue);
	// Set blending
	void SetBlendMode(SDL_BlendMode blending);
	// Set alpha modulation
	void SetAlpha(Uint8 alpha);
	// Renders texture at given point
	void Render(int x, 
		int y, 
		SDL_Rect* clip = NULL, 
		double angle = 0.0, 
		SDL_Point* center = NULL, 
		SDL_RendererFlip flip = SDL_FLIP_NONE) override;
	// Sets image dimensions
	void SetWidth(int);
	void SetHeight(int);

private:
	// Utility Functions
	SDL_Surface *LoadSurface(void) override;
	SDL_Texture *LoadTexture(SDL_Surface *texSurface) override;

	std::string imagePath;
};