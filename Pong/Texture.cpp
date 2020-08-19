#include "Texture.h"

Texture::~Texture()
{ 
	if (mTexture) SDL_DestroyTexture(mTexture);
}

Texture* Texture::Load(char* pPath, SDL_Renderer* pRenderer)
{
	SDL_Surface* tempSurface = IMG_Load(pPath); 
	if (!tempSurface)
	{
		std::cout << "Error! Failed to load image: " << IMG_GetError() << std::endl; 
		return NULL;
	}  

	SDL_Texture* tempTex = SDL_CreateTextureFromSurface(pRenderer, tempSurface); 
	SDL_FreeSurface(tempSurface); 
	if (tempTex)
	{
		int tWidth, tHeight; 
		SDL_QueryTexture(tempTex, NULL, NULL, &tWidth, &tHeight); 

		return new Texture(tempTex, tWidth, tHeight);
	} 
	else
	{
		std::cout << "Error! Failed to create texture: " << SDL_GetError() << std::endl; 
		return NULL;
	}
}
