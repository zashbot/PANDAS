#include "coreApp.h"


coreApp::coreApp()
{
	displaySurface = NULL;
	isRunning = true;
}

bool coreApp::onInit()
{
	// Load SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return false;
	}
		
	displaySurface = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_DOUBLEBUF | SDL_HWSURFACE);
	if (displaySurface == NULL) 
	{
		fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
		return false;
	}
	return true;
}

void coreApp::onCleanup()
{
	for(int i = 0; i < coreEntity::entityList.size(); i++) //cleans up all entities //ignore compiler warning here
	{
		if(!coreEntity::entityList[i]) continue; //skips the current iteration of the loop if the entity at that point is null for some reason. 

		coreEntity::entityList[i]->onCleanup();
	}
	coreEntity::entityList.clear(); 
	SDL_FreeSurface(displaySurface); //frees the screen from RAM
	SDL_Quit(); //quits SDL nicely
}

int coreApp::onExecute()
{
	if(onInit() == false)
	{
		return -1;
	}

	SDL_Event Event;
	
	while(isRunning)
	{
		while(SDL_PollEvent(&Event))
			onEvent(&Event);
		onLoop();
		onRender();
	}
	onCleanup();
	return 0;
}