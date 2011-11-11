#pragma once
#include <SDL.h>
#include <vector>
#include "coreTile.h"
#include "coreSurface.h"

class coreMap
{
public: 
	SDL_Surface* surfaceTileset;
private:
	std::vector<coreTile> tileList;
public:
	coreMap();

	bool onLoad(char* File);
	void onRender(SDL_Surface* displaySurface, int MapX, int MapY);

	 coreTile* getTile(int X, int Y);
};