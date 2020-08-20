#include "Player.h"

Player::Player()
{ 
	mPosition = Vector2(0, 0); 
	mTexture = NULL;
}

Player::Player(Vector2 pPosition, Texture* pTexture)
{ 
	mPosition = pPosition; 
	mTexture = pTexture;
}

void Player::Draw(SDL_Renderer* pRender)
{ 
	
	if (mTexture)
	{
		SDL_Rect tmpRect;
		tmpRect.w = mTexture->GetWidth();
		tmpRect.h = mTexture->GetHeight();
		tmpRect.x = (int)(this->mPosition.X - mTexture->GetWidth() / 2);
		tmpRect.y = (int)(this->mPosition.Y - mTexture->GetHeight() / 2);

		SDL_RenderCopy(pRender, mTexture->GetTexture(), NULL, &tmpRect);
	}
}

void Player::Update()
{ 
	int deltaY; //Change the paddle location

	//Handle Mouse Functionality 
	Uint32 mouseState = SDL_GetMouseState(NULL, &deltaY); 
	this->mPosition.Y = deltaY;
	//Handle Keyboard Functionality 
}


