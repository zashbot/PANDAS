#include "coreEntity.h"

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

//bool coreEntity::onLoad(char* File, int Width, int Height, int Maxframes)
//{
//	if((entSurface = coreSurface::onLoad(File)) == NULL)
//	{
//		fprintf(stderr, "Unable to initialize loading of entity's texture, reason: ", SDL_GetError());
//	}
//}