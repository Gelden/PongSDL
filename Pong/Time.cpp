#include "Time.h"

Time::Time()
{ 
	mStartTime = 0;
	mElapsedTime = 0;
	mDeltaTime = 0;
}

void Time::Tick()
{ 
	mElapsedTime = SDL_GetTicks() - mStartTime; 
	mDeltaTime = mElapsedTime * 0.001f;  
}

void Time::Reset()
{ 
	mStartTime = SDL_GetTicks();
	mElapsedTime = 0;
	mDeltaTime = 0;
}
