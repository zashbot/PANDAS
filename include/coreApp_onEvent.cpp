#include "coreApp.h"
 
void coreApp::onEvent(SDL_Event* Event) 
{
	//menu.displayGameMenu(displaySurface, Event);
	coreEvent::onEvent(Event);
}

void coreApp::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) 
{
 switch(sym)
	{
        case SDLK_LEFT: 
		{
            Player.moveLeft = true;
            break;
        }

		case SDLK_RIGHT:
		{
            Player.moveRight = true;
            break;
        }

		case SDLK_UP:
		{
			Player.onMove(0, -50);
			break;
		}

		case SDLK_ESCAPE:
		{
			gameMenu = true;
			//game state paused
			break;
		}
 
        default: 
		{
        }
    }    
}
void coreApp::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	switch(sym)
	{
        case SDLK_LEFT: 
		{
            Player.moveLeft = false;
            break;
        }
 
        case SDLK_RIGHT:
		{
            Player.moveRight = false;
            break;
        }
 
        default: 
		{
        }
    } 
}

void coreApp::onExit()
{
	menu.setIsRunning(false);
	isRunning = false;
	//gameMenu = false;
}