#include "coreAnimation.h"

coreAnimation::coreAnimation()
{
	currentFrame = 0;
	frameInc = 0; 
	
	frameRate = 100; //10 fps
	oldTime = 0; 

	maxFrames = 0;
	oscillate = false;
}
void coreAnimation::onAnimate()
{
	currentFrame += frameInc; //increments to next frame
	if(oldTime + frameRate > SDL_GetTicks())//if not enough time has passed
	{
		return;
	}
	oldTime = SDL_GetTicks();
	
	if(oscillate) //rtfm
	{
        if(frameInc > 0) 
		{
            if(currentFrame >= maxFrames) 
			{
                frameInc = -frameInc;
            }
        }
		else
		{
            if(currentFrame <= 0) 
			{
                frameInc = -frameInc;
            }
        }
    }
	else{
        if(currentFrame >= maxFrames) {
            currentFrame = 0;
        }
    }
}

void coreAnimation::setCurrentFrame(int Frame)
{
	currentFrame = Frame;
}
int coreAnimation::getCurrentFrame()
{
	return currentFrame;
}
void coreAnimation::setFrameRate(int Rate)
{
	frameRate = Rate;
}