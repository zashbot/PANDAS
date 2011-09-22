#include "coreApp.h"
 
void coreApp::onEvent(SDL_Event* Event) 
{
	coreEvent::onEvent(Event);
}

void coreApp::onExit()
{
	isRunning = false;
}