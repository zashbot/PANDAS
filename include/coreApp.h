#pragma once
#include <SDL.h>
#include <iostream>
#include "coreEvent.h"
#include "coreSurface.h"
#include "coreEntity.h"
#include "corePlayer.h"
#include "coreArea.h"
#include "coreCamera.h"
#include "define.h"

class coreApp : public coreEvent 
{
private:
	bool isRunning;	//used to quit the main game loop
	SDL_Surface* displaySurface; //the screen
public:
	coreApp();
	int onExecute();
	bool onInit();
	void onEvent(SDL_Event* Event); //separated into 3 different files
	void onLoop();					//
	void onRender();				//
	void onExit();
	void onCleanup();

	//players

	corePlayer Player;

	//events
	void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
	void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
};
