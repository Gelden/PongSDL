#pragma once 
#include "Player.h" 
#include "Time.h" 
#include "System.h" 
#include "Ball.h"
class Game
{ 
private: 
	Texture* mBackground;  
	Player* mPlayer;   
	Ball* mBall;
public: 
	Game() : mBackground(NULL), mPlayer(NULL), mBall(NULL) {}
	~Game() {}

	bool Initialize();
	void Draw();
	void Update(float dt);  

	float WorldLeft() const { return 0.0f; }
	float WorldRight() const { return (float)System::GetScreenWidth(); }
	float WorldTop() const { return 0.0f; }
	float WorldBottom() const { return (float)System::GetScreenHeight(); }
};