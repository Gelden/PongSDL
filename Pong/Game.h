#pragma once 
#include "Player.h" 
#include "Time.h" 
#include "System.h"
class Game
{ 
private: 
	Texture* mBackground;  
	Player* mPlayer;  
public: 
	Game() : mBackground(NULL), mPlayer(NULL) {}
	~Game() {}

	bool Initialize();
	void Draw();
	void Update(float dt);
};