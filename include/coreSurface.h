#pragma once
#include <SDL.h>
#include <string>
using namespace std;
class coreSurface
{
public:
	coreSurface();
	static SDL_Surface* onLoad(char* Filename);
	static bool onDraw(SDL_Surface* s_destination, /*usually displaySurface*/ SDL_Surface* s_source, int X, int Y); //drawing a full image on screen
	static bool onDraw(SDL_Surface* s_destination, /*usually displaySurface*/ SDL_Surface* s_source, int X, int Y, int X2, int Y2, int W, int H);//drawing part of an image, as in a tileset or frameset
	static bool Transparent(SDL_Surface* s_destination, int R, int G, int B);
};