#include <SDL2/SDL_image.h>
#include "texture.h"
#include "mandala.h"

LTexture::LTexture()
{
	//Initialize
	texture = NULL;
	width = 0;
	height = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	Free();
}

bool LTexture::LoadFromFile(std::string path)
{
	//Get rid of preexisting texture
	Free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = LoadImageFromSurface(path);

    //Create texture from surface pixels
    newTexture = LoadTexture(loadedSurface);
    
    //Get image dimensions
    width = loadedSurface->w;
    height = loadedSurface->h;

    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);

	//Return success
	texture = newTexture;
	return texture != NULL;
}

void LTexture::Free()
{
	//Free texture if it exists
	if( texture != NULL )
	{
		SDL_DestroyTexture( texture );
		texture = NULL;
		width = 0;
		height = 0;
	}
}

void LTexture::SetColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( texture, red, green, blue );
}

void LTexture::SetBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( texture, blending );
}
		
void LTexture::SetAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( texture, alpha );
}

void LTexture::Render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, width, height };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( Mandala::Instance()->GetRenderer(), texture, clip, &renderQuad, angle, center, flip );
}

int LTexture::GetWidth()
{
	return width;
}

int LTexture::GetHeight()
{
	return height;
}

void LTexture::SetWidth(int w)
{
	width = w;
}

void LTexture::SetHeight(int h)
{
    height = h;
}

SDL_Texture* LTexture::GetRawTexture()
{
    return texture;
}

SDL_Surface* LTexture::LoadImageFromSurface(std::string path)
{
    SDL_Surface* imgSurface = IMG_Load(path.c_str());
    if (!imgSurface)
    {
        printf("Error creating SDL_Surface: %s\n", IMG_GetError());
        return NULL;
    }
    else
    {
        SDL_Surface* optimizedSurface = SDL_ConvertSurface(imgSurface, Mandala::Instance()->GetScreenSurface()->format, NULL);
        if (!optimizedSurface)
        {
            printf("Error optimizing SDL_Surface: %s\n ...Returning loaded surface.\n", SDL_GetError());
            return imgSurface;
        }
        else
        {
            SDL_FreeSurface(imgSurface);
            return optimizedSurface;
        }
    }
}

SDL_Texture* LTexture::LoadTexture(SDL_Surface* texSurface)
{
    // Load image into renderer hardware memory
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Mandala::Instance()->GetRenderer(), texSurface);
    if (!texture)
    {
        printf("Error creating SDL_Texture: %s\n", SDL_GetError());
        return NULL;
    }

    // Loading success
    return texture;
}