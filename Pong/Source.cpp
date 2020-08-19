#include <iostream> 
#include "System.h"
#include "Game.h"

namespace {

	SDL_Window* window = NULL; //Game Window
	SDL_Renderer* gRenderer = NULL; //Renderer 
	int screenWidth = 1280;  //Defualt Screen Width
	int screenHeight = 960; //Default Screen Height 
	Time gTime = Time();
} 

namespace System
{
	SDL_Renderer* GetRenderer() { return gRenderer; } 
	int GetScreenWidth() { return screenWidth; } 
	int GetScreenHeight() { return screenHeight;} 
}

int main(int argc, char** argv)
{

	const Uint8* keys = NULL; //Pointer to keyboard state 
	bool isRunning = true; //Game Loop Flag  
	
	//Initalize SDL  
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Failed to initalize SDL: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if (!window)
	{
		fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
		return 1;
	}  

	gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!gRenderer)
	{
		fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		return 1;
	}

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

		//Time to draw shit 
	/*	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
		SDL_RenderClear(gRenderer); */
		mGame.Update(gTime.DeltaTime());
		/*SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);  */
		SDL_RenderPresent(gRenderer);
	}
	SDL_Quit(); 
	return 0;
} 

