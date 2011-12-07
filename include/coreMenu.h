#ifndef COREMENU_H
#define COREMENU_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>

#include "coreSurface.h"
#include "coreEvent.h"

using namespace std;

class coreMenu
{
    private:
		int x;
		int y;
		bool MainMenu;
		bool OptionsMenu;
		bool isRunning;

		SDL_Surface* displaySurface;
		SDL_Surface* mainMenu;
		SDL_Surface* optionsMenu;
		SDL_Surface* optionsButtonSheet;
		SDL_Surface* backButtonSheet;
		SDL_Surface* exitButtonSheet;
		SDL_Surface* loadButtonSheet;
		SDL_Surface* scoreButtonSheet;
		SDL_Surface* startButtonSheet;

		Mix_Music* music;

		coreSurface surface;

	public:
		coreMenu();
		bool getMainMenu();
		bool getOptionsMenu();
		bool getIsRunning();
		void setMainMenu(bool m);
		void setOptionsMenu(bool o);
		void setIsRunning(bool i);


		bool displayGameMenu(SDL_Surface* displaySurface, SDL_Event* Event); //Displays the menu and all its functionality
		//void displayGameMenu(SDL_Surface* displaySurface, SDL_Event* Event); //Displays the menu and all its functionality
		void onCleanup(); //Clears all surfaces used by the menu
		SDL_Surface* onLoad(std::string filename); //Can load any image type
		bool onInitialize(); //Loads all images and sounds necessary for the menu

};
 
#endif