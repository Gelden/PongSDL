#include "Ball.h"

Ball::Ball()
{ 
	mTexture = NULL; 
	mPosition = Vector2(0, 0); 
	mSpeedY = 0; 
	mSpeedX = 0;
}

Ball::Ball(Vector2 pPosition, Texture* pTexture)
{ 
	mPosition = pPosition; 
	mTexture = pTexture; 
	mSpeedY = 0; 
	mSpeedX = 0;
}

void Ball::Update()
{ 
	mPosition.X += mSpeedX; 
	mPosition.Y += mSpeedY; 
}

void Ball::Reset()
{  
	//Reset the Position 
	mPosition.X = System::GetScreenWidth() / 2; //Start in the middle; 
	mPosition.Y = 0; 
	mSpeedX = 10.0f; 
	mSpeedY = 10.0f;
}

void Ball::Draw(SDL_Renderer* pRenderer)
{ 
	if (mTexture)
	{
		SDL_Rect tmpRect;
		tmpRect.w = mTexture->GetWidth();
		tmpRect.h = mTexture->GetHeight();
		tmpRect.x = (int)(this->mPosition.X - mTexture->GetWidth() / 2);
		tmpRect.y = (int)(this->mPosition.Y - mTexture->GetHeight() / 2);

		SDL_RenderCopy(pRenderer, mTexture->GetTexture(), NULL, &tmpRect);
	}
}
