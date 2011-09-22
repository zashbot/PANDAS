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
	s_return = SDL_DisplayFormat(s_temp); // this is so s_return is the same format as the display surface.
	SDL_FreeSurface(s_temp); 

	return s_return;
}

bool coreSurface::onDraw(SDL_Surface* s_destination, SDL_Surface* s_source, int X, int Y)
{
	if(s_destination == NULL || s_source == NULL)
	{
		fprintf(stderr, "Error: Draw function was passed a null value for a surface");
		return false;
	}
	
	SDL_Rect destRec;
	destRec.x = X;
	destRec.y = Y;

	SDL_BlitSurface(s_source, NULL,/*this is null because we are drawing the entire image*/ s_destination, &destRec); //takes s_source, draws it on destRec, and then draws destRec onto s_destination

	return true;
}

bool coreSurface::onDraw(SDL_Surface* s_destination, SDL_Surface* s_source, int X, int Y, int X2, int Y2, int W, int H)
{
	if(s_destination == NULL || s_source == NULL)
	{
		fprintf(stderr, "Error: Draw function was passed a null value for a surface");
		return false;
	}
	SDL_Rect destRec;
	destRec.x = X;
	destRec.y = Y;

	SDL_Rect srcRec; //the part of the image we will be drawing from, remember the upper left corner of the image is the origin. 
	srcRec.x = X2;
	srcRec.y = Y2;
	srcRec.w = W;
	srcRec.h = H;

	SDL_BlitSurface(s_source, &srcRec, s_destination, &destRec);

	return true;
}