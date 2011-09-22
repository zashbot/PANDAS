#pragma once

#include <SDL.h>

class coreAnimation
{
private:
	int currentFrame;
	int frameInc; //frame increment value
	
	int frameRate; //in milliseconds
	long oldTime; //previous tick value
public:
	int maxFrames;
	bool oscillate;
	coreAnimation();
	void onAnimate();
	void setCurrentFrame(int Frame);
	int getCurrentFrame();
	void setFrameRate(int Rate);
};