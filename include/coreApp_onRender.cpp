#include "coreApp.h"

void coreApp::onRender()
{
	SDL_Rect Rect;
	Rect.x = 0;
	Rect.y = 0;
	Rect.w = WWIDTH;
	Rect.h = WHEIGHT;

	SDL_FillRect(displaySurface, &Rect, 255);


//MAP
	coreArea::areaControl.onRender(displaySurface, -coreCamera::cameraControl.getX(), -coreCamera::cameraControl.getY());

//ENTITIES	
	for(int i = 0; i < coreEntity::entityList.size(); i++)
	{
		if(!coreEntity::entityList[i]) continue; //skips the current iteration of the loop if the entity at that point is null for some reason. 

		coreEntity::entityList[i]->onRender(displaySurface);
	}

//FLIP BACKBUFFER	
	SDL_Flip(displaySurface);
}