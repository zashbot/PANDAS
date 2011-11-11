#include "coreFPS.h"

coreFPS coreFPS::FPScounter;

coreFPS::coreFPS()
{
	oldTime = 0;
	lastTime = 0;
	frames = 0;
	numFrames = 0;
	speedFactor = 0;
}

void coreFPS::onLoop()
{
	if(oldTime + 1000 < SDL_GetTicks())
	{
		oldTime = SDL_GetTicks();
		numFrames = frames;
		frames = 0;
	}
	speedFactor = ((SDL_GetTicks() - lastTime) / 1000.0f) * 32.0f;
	lastTime = SDL_GetTicks();
	frames++;
}

int coreFPS::getFrames()
{
	return frames;
}
float coreFPS::getSpeedFactor()
{
	return speedFactor;
}