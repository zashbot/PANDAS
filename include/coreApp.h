#pragma once
#include <SDL.h>
#include "coreEvent.h"
#include "coreSurface.h"

class coreApp : public coreEvent 
{
private:
	bool isRunning;	//used to quit the main game loop
	SDL_Surface* displaySurface; 
public:
	coreApp();
	int onExecute();
	bool onInit();
	void onEvent(SDL_Event* Event); //separated into 3 different files because they are going to be huge functions
	void onLoop();					//
	void onRender();				//
	void onExit();
	void onCleanup();
};
