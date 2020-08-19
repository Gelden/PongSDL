#pragma once 
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>  


class Texture
{

	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
	Texture(SDL_Texture* pTexture, int pWidth, int pHeight) : mTexture(pTexture), mWidth(pWidth), mHeight(pHeight) {}
	~Texture();

public:

	static Texture* Load(char* pPath, SDL_Renderer* pRenderer);
	int GetWidth() { return mWidth; }
	int GetHeight() { return mHeight; } 
	SDL_Texture* GetTexture() { return mTexture; }

};