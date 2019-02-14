#include <string>
#include <SDL2/SDL.h>

//Texture wrapper class
class Texture
{
	public:
		// Initializes variables
		Texture();

		// Deallocates memory
		~Texture();

		// Loads image at specified path
		bool LoadFromFile(std::string path);

		// Deallocates texture
		void Free();

		// Set color modulation
		void SetColor(Uint8 red, Uint8 green, Uint8 blue);

		// Set blending
		void SetBlendMode(SDL_BlendMode blending);

		// Set alpha modulation
		void SetAlpha(Uint8 alpha);
		
        // Renders texture at given point
		void Render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

		// Gets image dimensions
		int GetWidth();
		int GetHeight();

        // Sets image dimensions
        void SetWidth(int);
        void SetHeight(int);

        // Return the actual texture
        SDL_Texture* GetRawTexture();

	private:
		//The actual hardware texture
		SDL_Texture* texture;

		//Image dimensions
		int width;
		int height;

        // Utility Functions
        SDL_Surface* LoadImageFromSurface(std::string path);
        SDL_Texture* LoadTexture(SDL_Surface* texSurface);
};