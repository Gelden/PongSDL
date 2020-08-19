#include "Time.h"

Time::Time()
{ 
	Reset();
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
