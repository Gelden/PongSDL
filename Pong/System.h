#pragma once  
#include <SDL.h>  
#include "Time.h"
namespace System
{
	SDL_Renderer* GetRenderer(); 
	
	int GetScreenWidth();
	int GetScreenHeight(); 

	float GetDeltaTime(); 

	bool Initialize();
}
