#include<iostream> 
#include<SDL.h>   
#include"Player.h"


int main(int argc, char** argv)
{
	//Component Setup

	SDL_Window* window = NULL; //Game Window
	SDL_Renderer* renderer = NULL; //Renderer
	const Uint8* keys = NULL; //Pointer to keyboard state 
	bool isRunning = true; //Game Loop Flag  
	int screenWidth = 1280;  //Defualt Screen Width
	int screenHeight = 960; //Default Screen Height

	

	
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

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
	{
		fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		return 1;
	}

	keys = SDL_GetKeyboardState(NULL); //Get Keyboard State

	//Initialize Game  
	Player player1 = Player(Vector2(20, screenHeight/2), Texture::Load("Sprites\\PlayerSprite.jpg", renderer));

	//main game loop 

	while (isRunning)
	{
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

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  
		player1.Update();
		player1.Draw(renderer);
	/*	SDL_RenderFillRect(renderer, &playerLeft);
		SDL_RenderFillRect(renderer, &playerRight); 
		SDL_RenderFillRect(renderer, &ball);  
		SDL_RenderFillRect(renderer, &rect1);*/
		SDL_RenderPresent(renderer);
	}
	SDL_Quit(); 
	return 0;
} 

