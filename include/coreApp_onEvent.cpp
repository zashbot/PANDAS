#include "coreApp.h"
 
void coreApp::onEvent(SDL_Event* Event) 
{
	coreEvent::onEvent(Event);
}

void coreApp::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_UP:    coreCamera::cameraControl.onMove( 0,  5); break;
        case SDLK_DOWN:  coreCamera::cameraControl.onMove( 0, -5); break;
        case SDLK_LEFT:  coreCamera::cameraControl.onMove( 5,  0); break;
        case SDLK_RIGHT: coreCamera::cameraControl.onMove(-5,  0); break;
 
        default: {
        }
    }
}

void coreApp::onExit()
{
	isRunning = false;
}