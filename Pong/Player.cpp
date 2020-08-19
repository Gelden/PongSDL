#include "Player.h"

Player::Player()
{ 
	mTranform = Vector2(0, 0); 
	mTexture = NULL;
}

Player::Player(Vector2 pPosition, Texture* pTexture)
{ 
	mTranform = pPosition; 
	mTexture = pTexture;
}

void Player::Draw(SDL_Renderer* pRender)
{ 
	
	if (mTexture)
	{
		SDL_Rect tmpRect;
		tmpRect.w = mTexture->GetWidth();
		tmpRect.h = mTexture->GetHeight();
		tmpRect.x = (int)(this->mTranform.X - mTexture->GetWidth() / 2);
		tmpRect.y = (int)(this->mTranform.Y - mTexture->GetHeight() / 2);

		SDL_RenderCopy(pRender, mTexture->GetTexture(), NULL, &tmpRect);
	}
}

void Player::Update()
{ 
	int deltaY; //Change the paddle location

	//Handle Mouse Functionality 
	Uint32 mouseState = SDL_GetMouseState(NULL, &deltaY); 
	this->mTranform.Y = deltaY;
	//Handle Keyboard Functionality 
}


