#pragma once 
#include "GameObject.h" 
#include "System.h"
class Ball : public GameObject
{
private: 
	float mSpeedX; 
	float mSpeedY; 
public: 
	Ball(); 
	~Ball(){} 

	Ball(Vector2 pPosition, Texture* pTexture); 
	void Update(float dt); 
	void Reset(); //Resets the ball after at the beginning of the game or if a player scores;
	void Draw(SDL_Renderer* pRenderer);    

	//ACCESSORS
	void SetXSpeed(float pXSpeed) { mSpeedX = pXSpeed; } 
	void SetYSpeed(float pYSpeed) { mSpeedY = pYSpeed; } 
	float GetXSpeed() { return mSpeedX; } 
	float GetYSpeed() { return mSpeedY; }

};