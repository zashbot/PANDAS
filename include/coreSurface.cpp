#include "coreSurface.h"

coreSurface::coreSurface()
{
}

SDL_Surface* coreSurface::onLoad(char* Filename)
{
	SDL_Surface* s_temp; s_temp = NULL;
	SDL_Surface* s_return; s_return = NULL;
	if ((s_temp = SDL_LoadBMP(Filename))==NULL)
	{
		fprintf(stderr, "Unable to load bitmap ", Filename," because: ", SDL_GetError());
		return NULL;
	}
