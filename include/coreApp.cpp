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
	
	if(coreArea::areaControl.onLoad("./maps/1.area") == false)
	{
		return false;
		fprintf(stderr, "Unable to load map");
	}
	
	if(Player.onLoad("./img/panda.bmp", 64, 64, 8, "test player") == false)
	{
		//error message here
		return false;
	}

	coreEntity::entityList.push_back(&Player);

	coreCamera::cameraControl.targetMode = TARGET_MODE_CENTER;
	coreCamera::cameraControl.setTarget(&Player.X, &Player.Y);

	SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);
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
	coreArea::areaControl.onCleanup();
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
		SDL_Delay(1);
	}
	onCleanup();
	return 0;
}

