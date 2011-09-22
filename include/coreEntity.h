#pragma once
#include <vector>
#include "coreAnimation.h"
#include "coreSurface.h"
class coreEntity
{
public:
	static	std::vector<coreEntity*> entityList;

protected:
	coreAnimation animControl;
	SDL_Surface* entSurface;

public:
	float X, Y;
	int Width, Height;
	int animState;

	coreEntity();
	virtual ~coreEntity();

	virtual bool onLoad(char* File, int Width, int Height, int Maxframes);
	virtual void onLoop();
	virtual void onRender(SDL_Surface* displaySurface);
	virtual void onCleanup();
};

