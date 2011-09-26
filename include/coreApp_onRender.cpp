#include "coreApp.h"

void coreApp::onRender() //calls onrender on every entity in the entity vector
{
	for(int i = 0; i < coreEntity::entityList.size(); i++)
	{
		if(!coreEntity::entityList[i]) continue; //skips the current iteration of the loop if the entity at that point is null for some reason. 

		coreEntity::entityList[i]->onRender(displaySurface);
	}
}