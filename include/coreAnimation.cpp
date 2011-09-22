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
	if(oldTime + frameRate > SDL_GetTicks())//if not enough time has passed
	{
		return;
	}
	oldTime = SDL_GetTicks();
	currentFrame += frameInc; //increments to next frame
	
	if(oscillate) //rtfm
	{
        if(frameInc > 0) 
		{
            if(currentFrame >= maxFrames - 1) 
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
        if(currentFrame >= maxFrames - 1) {
            currentFrame = 0;
        }
    }
}
