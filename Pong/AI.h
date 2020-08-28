#pragma once 
#include "GameObject.h" 
#include "System.h"
class AI : GameObject
{ 
private: 
	float mSpeed;
public:
	AI();
	AI(Vector2 pPosition, Texture* pTexture);
	void Draw(SDL_Renderer* pRender);
	void PredictBallPath(float yPos); 
	void Update();
};