#pragma once 
#include <SDL_timer.h>
class Time
{
private:
	Uint32 mStartTime;
	Uint32 mElapsedTime;
	float mDeltaTime;

public:
	Time();
	~Time() {}
	void Tick();
	void Reset();
	float DeltaTime() { return mDeltaTime; } 
};
