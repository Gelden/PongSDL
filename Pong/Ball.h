#pragma once 
#include "GameObject.h"
class Ball : GameObject
{
private: 
	float mSpeed; 
public: 
	Ball(); 
	~Ball(){} 

	Ball(Vector2 pPosition, Texture* pTexture); 
	void Update(float dt); 
	void Draw(SDL_Renderer* pRenderer);     
	void HandleCollision(); 
};