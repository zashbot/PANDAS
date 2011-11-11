#pragma once

#include <SDL.h>

class coreFPS
{
public:
	static coreFPS FPScounter;
private:
	int oldTime;
	int lastTime;
	int frames;
	int numFrames;
	float speedFactor;
public:
	coreFPS();
	void onLoop();
	int getFrames();
	float getSpeedFactor();
};