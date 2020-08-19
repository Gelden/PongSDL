#pragma once 
#include "Player.h" 
#include "Time.h"
class Game
{ 
private: 
	Texture* mBackground;  
	Player mPlayer;  
	Time mTimer;
public: 
	Game(); 
	~Game(); 

	bool Initialize(); 
	void Shutdown(); 
	void Update(float dt);

};