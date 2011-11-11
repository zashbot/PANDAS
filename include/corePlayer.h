#pragma once

#include "coreEntity.h"

class corePlayer : public coreEntity
{
public:
	corePlayer();
	bool onLoad(char* File, int Width, int Height, int Maxframes, char* name);
	void onLoop();
	void onRender(SDL_Surface* displaySurface);
	void onCleanup();
	void onAnimate();
	void onCollision(coreEntity* entity);
};