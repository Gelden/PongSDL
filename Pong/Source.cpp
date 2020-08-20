#include <iostream> 
#include "System.h"
#include "Game.h"

namespace {

	SDL_Window* gWindow = NULL; //Game Window
	SDL_Renderer* gRenderer = NULL; //Renderer 
	int screenWidth = 1280;  //Defualt Screen Width
	int screenHeight = 960; //Default Screen Height 
	Time gTime = Time(); 
	int FPS = 60; 
	int frameDelay = 1000 / FPS;

} 

namespace System
{
	SDL_Renderer* GetRenderer() { return gRenderer; } 
	int GetScreenWidth() { return screenWidth; } 
	int GetScreenHeight() { return screenHeight;}  
	float GetDeltaTime() { return gTime.DeltaTime(); } 

	bool Initialize()
	{ 
		//Initalize SDL  
		gWindow = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (!gWindow)
		{
			fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
			return false;
		}

		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!gRenderer)
		{
			fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
			SDL_DestroyWindow(gWindow);
			return false;
		}
	}
}

int main(int argc, char** argv)
{

	if(!System::Initialize()) return 1; 

	const Uint8* keys = NULL; //Pointer to keyboard state 
	bool isRunning = true; //Game Loop Flag  
	
	keys = SDL_GetKeyboardState(NULL); //Get Keyboard State

	Game mGame = Game(); 
	if (!mGame.Initialize())
		return 1; 
	gTime.Reset();
									   
	//main game loop
	while (isRunning)
	{
		gTime.Tick();  
	
		
		SDL_Event e; //Event handler 

		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				printf("User closed the window\n");
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					printf("User pressed Escape\n");
					isRunning = false;
					break;
				}
				break;
			}
		}  

		mGame.Update(gTime.DeltaTime());
		SDL_RenderPresent(gRenderer);  

		//FPS Lock @60
		if (1000 / FPS > gTime.DeltaTime())
		{
			SDL_Delay(frameDelay - gTime.DeltaTime());
		}
	}
	SDL_Quit(); 
	return 0;
} 

