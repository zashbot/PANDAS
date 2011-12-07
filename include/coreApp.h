#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "coreEvent.h"
#include "coreSurface.h"
#include "coreEntity.h"
#include "corePlayer.h"
#include "coreArea.h"
#include "coreCamera.h"
#include "define.h"
#include "coreMenu.h"

class coreApp : public coreEvent 
{
private:
	//bool isRunning;	//used to quit the main game loop
	bool gameMenu; //used to quit the menu and go to main game loop
	SDL_Surface* displaySurface; //the screen
	Mix_Music* music;

public:
	coreApp();
	//SDL_Event Event;
	bool isRunning;	//used to quit the main game loop
	int onExecute();
	bool onInit();
	void onEvent(SDL_Event* Event); //separated into 3 different files
	void onLoop();					//
	void onRender();				//
	void onExit();
	void onCleanup();

	//the game's main menu
	coreMenu menu; 

	//players
	corePlayer Player;

	//events
	void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
	void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
	//void onLButtonDown(Event->button.x,Event->button.y);
};
