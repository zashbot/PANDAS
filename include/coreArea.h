#pragma once

#include "coreMap.h"

class coreArea
{
public:
	static coreArea	areaControl;
	std::vector<coreMap> mapList;

private:
	int areaSize; //will change later so that you can have a non square area
	SDL_Surface* surfaceTileset;

public:
	coreArea();
	bool onLoad(char* File);
	void onRender(SDL_Surface* displaySurface, int cameraX, int cameraY);
	void onCleanup();
};