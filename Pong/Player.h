/************************************************************************************** 
 * A Player is a GameObject that takes input from the user though the Update Function *                         
 * Written By: Gelden                                                                 *
 * August 2020                                                                        *
 **************************************************************************************/ 

#pragma once 
#include "GameObject.h" 

class Player : public GameObject
{	 

public: 
	Player(Vector2 pPosition, Texture* pTexture); 
	void Draw(SDL_Renderer* pRender); 
	void Update();
};