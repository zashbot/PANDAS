#pragma once
#include <SDL.h>
#include <string>
using namespace std;
class coreSurface
{
public:
	coreSurface();
	static SDL_Surface* onLoad(char* Filename);

};