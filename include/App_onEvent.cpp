#include "App.h"
 
void App::onEvent(SDL_Event* Event) 
{
	if(Event->type == SDL_QUIT) {
        isRunning = false; //quits the loop if the user presses the "x" on the window
    }
}