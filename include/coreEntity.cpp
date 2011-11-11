#include "coreEntity.h"

std::vector<coreEntity*> coreEntity::entityList; //declaring static member variable

coreEntity::coreEntity()
{
	entSurface = NULL;
	X = Y = 0.0;
	Width = Height = 0;
	animState = 0;
}
coreEntity::~coreEntity()
{
	//does nothing unless entity has dynamically allocated variables
}

bool coreEntity::onLoad(char* File, int Width, int Height, int Maxframes, char* name)
{
	if((entSurface = coreSurface::onLoad(File)) == NULL)
	{
		fprintf(stderr, "Unable to initialize loading of entity's texture, reason: ", SDL_GetError());
	}
	coreSurface::Transparent(entSurface, 255, 0, 255);
	
	this->Height = Height;
	this->Width = Width;
	animControl.maxFrames = Maxframes;
	return true;
}

void coreEntity::onLoop()
{
	animControl.onAnimate();
}

void coreEntity::onRender(SDL_Surface* displaySurface)
{
	if(entSurface == NULL)
	{
		fprintf(stderr, "Entity tried to draw itself with no surface loaded");
		return;
	}
	if(displaySurface == NULL)
	{
		fprintf(stderr, "Entity tried to draw itself to a NULL screen pointer");
		return;
	}
	coreSurface::onDraw(displaySurface, entSurface, (int)X, (int)Y, animState * Width, animControl.getCurrentFrame() * Height, Width, Height);
}

void coreEntity::onCleanup()
{
	if(entSurface)
	{
		SDL_FreeSurface(entSurface);
	}
	entSurface = NULL;
}
