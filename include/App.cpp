#include "App.h"


App::App()
{
	displaySurface = NULL;
	isRunning = true;
}

bool App::onInit()
{
	// Load SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return false;
	}
		
	displaySurface = SDL_SetVideoMode(720, 480, 32, SDL_DOUBLEBUF | SDL_HWSURFACE);
	if (displaySurface == NULL) 
	{
		fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
		return false;
	}
	return true;
}

void App::onCleanup()
{
	SDL_Quit(); //quits SDL nicely
}

int App::onExecute()
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