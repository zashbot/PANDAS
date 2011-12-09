#pragma once

#include "coreMap.h"

class coreArea
{
public:
	static coreArea	areaControl;
	std::vector<coreMap> mapList;

private:
	int areaSizeX;
	int areaSizeY;
	SDL_Surface* surfaceTileset;
	SDL_Surface* mapBackground;

public:
	coreArea();
	bool onLoad(char* File);
	void onRender(SDL_Surface* displaySurface, int cameraX, int cameraY);
	void onCleanup();

	coreMap* getMap(int X, int Y);
	coreTile* getTile(int X, int Y);
};