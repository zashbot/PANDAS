#include "corePlayer.h"

corePlayer::corePlayer()
{
	maxSpeedX = 10;
	maxSpeedY = 20;
}

bool corePlayer::onLoad(char* File, int Width, int Height, int Maxframes, char* name)
{
	if(coreEntity::onLoad(File, Width, Height, Maxframes, name) == false)
	{
		//error statement here
		return false;
	}
	return true;
}

void corePlayer::onLoop()
{
	coreEntity::onLoop();
}

void corePlayer::onRender(SDL_Surface* displaySurface)
{
	coreEntity::onRender(displaySurface);
}

void corePlayer::onCleanup()
{
	coreEntity::onCleanup();
}
void corePlayer::onAnimate() 
{
    if(speedX != 0) 
	{
        animControl.maxFrames = 4;
    }else
	{
        animControl.maxFrames = 0;
    }
 
    coreEntity::onAnimate();
}
void corePlayer::onCollision(coreEntity* entity)
{
}