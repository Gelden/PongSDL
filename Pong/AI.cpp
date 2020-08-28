#include "AI.h"

AI::AI()
{ 
	mPosition = Vector2(0, 0); 
	mTexture = NULL; 
	mSpeed = 0.f;
}

AI::AI(Vector2 pPosition, Texture* pTexture)
{ 
	mPosition = pPosition; 
	mTexture = pTexture; 
	mSpeed = 10.0f;
} 

void AI::Draw(SDL_Renderer* pRender)
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

void AI::PredictBallPath(float yPos)
{ 
	float deltaY = mPosition.Y;
	if (yPos > mPosition.Y)
	{
		deltaY += mSpeed * System::GetDeltaTime();
	} 
	else if(yPos< mPosition.Y) 
	{
		deltaY -= mSpeed * System::GetDeltaTime();
	} 
	mPosition.Y = deltaY;
}

void AI::Update(float dt)
{ 

}

