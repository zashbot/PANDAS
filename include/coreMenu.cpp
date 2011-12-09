#include "coreMenu.h"

coreMenu::coreMenu()
{
	//Initialize all menu surfaces (buttons and screens)
	displaySurface = NULL;
	mainMenu = NULL;
	optionsMenu = NULL;
	optionsButtonSheet = NULL;
	backButtonSheet = NULL;
	exitButtonSheet = NULL;
	loadButtonSheet = NULL;
	scoreButtonSheet = NULL;
	startButtonSheet = NULL;

	//Initialize audio component
	music = NULL;

	//Initialize Boolean
	isRunning = true;
}

bool coreMenu::getMainMenu()
{
	return MainMenu;
}

bool coreMenu::getOptionsMenu()
{
	return OptionsMenu;
}

bool coreMenu::getIsRunning()
{
	return isRunning;
}

void coreMenu::setMainMenu(bool m)
{
	MainMenu = m;
}

void coreMenu::setOptionsMenu(bool o)
{
	OptionsMenu = o;
}

void coreMenu::setIsRunning(bool i)
{
	isRunning = i;
}

void coreMenu::onCleanup()
{
	//Free surfaces from menu
	SDL_FreeSurface(displaySurface);
	SDL_FreeSurface(mainMenu);
	SDL_FreeSurface(optionsMenu);
	SDL_FreeSurface(optionsButtonSheet);
	SDL_FreeSurface(backButtonSheet);
	SDL_FreeSurface(exitButtonSheet);
	SDL_FreeSurface(loadButtonSheet);
	SDL_FreeSurface(scoreButtonSheet);
	SDL_FreeSurface(startButtonSheet);

	//Free the music
    Mix_FreeMusic( music );

	//Quit SDL_mixer
    Mix_CloseAudio();
}

SDL_Surface* coreMenu::onLoad(std::string filename)
{
	SDL_Surface* tempImg = NULL; // Image that will be loaded
	SDL_Surface* returnImg = NULL; //Image that will be returned and used

	if((tempImg = IMG_Load(filename.c_str())) == NULL)
	{
		fprintf(stderr, "Failed to open menu file ", filename);
		return NULL;
	}

	//Create an optimized surface
	returnImg = SDL_DisplayFormat(tempImg);

    //Free the old surface
    SDL_FreeSurface(tempImg);

	//Return the otimized surface
    return returnImg;
}

bool coreMenu::onInitialize()
{
	//Load menu screens
	if((mainMenu = onLoad("./img/mainMenu.png")) == NULL) //Initializes main menu and checks if loaded correctly
	{
		return false;
	}
	if((optionsMenu = onLoad("./img/instructionMenu.png")) == NULL) //Initializes instruction menu and checks if loaded correctly
	{
		return false;
	}

	//Load Buttons for menu screens
	if((optionsButtonSheet = onLoad("./img/newOptionsButton1.png")) == NULL)
	{
		return false;
	}
	if((backButtonSheet = onLoad("./img/newBackButton1.png")) == NULL)
	{
		return false;
	}
	if((exitButtonSheet = onLoad("./img/newExitButton1.png")) == NULL)
	{
		return false;
	}
	if((loadButtonSheet = onLoad("./img/newLoadButton2.png")) == NULL)
	{
		return false;
	}
	if((scoreButtonSheet = onLoad("./img/newScoreButton1.png")) == NULL)
	{
		return false;
	}
	if((startButtonSheet = onLoad("./img/newStartButton1.png")) == NULL)
	{
		return false;
	}

	//Load Music
	if((music = Mix_LoadMUS( "./sfx/menuThemeBeat.wav" )) == NULL) // Panda.wav or menuThemeBeat.wav
	{
		return false;
	}
	
	//Set the window caption
	SDL_WM_SetCaption( "BadAss Panda: Endanger THIS!", NULL );

	//If everything loaded fine
    return true;
}
//void
bool coreMenu::displayGameMenu(SDL_Surface* displaySurface, SDL_Event* Event)
{
	int x=0,y=0;
	setMainMenu(true);

	if(getMainMenu() == true)
	{
		//Draw the main menu to the screen
		coreSurface::onDraw(displaySurface, mainMenu, 0,0);
		
		//Mouse out is default button displayed in main menu
		coreSurface::onDraw(displaySurface, exitButtonSheet, 507,230, 125,0,125,96); //Exit
		coreSurface::onDraw(displaySurface, optionsButtonSheet, 382,277, 125,0,125,96); //Options
		coreSurface::onDraw(displaySurface, scoreButtonSheet, 257,230, 125,0,125,96); //Score
		coreSurface::onDraw(displaySurface, loadButtonSheet, 132,277, 125,0,125,96); //Load
		coreSurface::onDraw(displaySurface, startButtonSheet, 7,230, 125,0,125,96); //Start

		//If the mouse moved
		if(Event->type == SDL_MOUSEMOTION)
		{
			//Get the mouse offsets
			x = Event->motion.x;
			y = Event->motion.y;

			//If the mouse is over the exit button
			if( ( x > 507 ) && ( x < 632 ) && ( y > 277 ) && ( y < 326 ) )
			{
				coreSurface::onDraw(displaySurface, exitButtonSheet, 505,230, 0,0,125,96); //mouse over button
			}
			//If not
			else
			{
				//Set the button sprite
				coreSurface::onDraw(displaySurface, exitButtonSheet, 507,230, 125,0,125,96);//mouse out of button
			}

			//If the mouse is over the options button
			if( ( x > 382 ) && ( x < 507 ) && ( y > 277 ) && ( y < 326 ) )
			{
				coreSurface::onDraw(displaySurface, optionsButtonSheet, 380,277, 0,0,125,96); //mouse over button
			}
			//If not
			else
			{
				//Set the button sprite
				coreSurface::onDraw(displaySurface, optionsButtonSheet, 382,277, 125,0,125,596);//mouse out of button
			}

			//If the mouse is over the score button
			if( ( x > 257 ) && ( x < 382 ) && ( y > 277 ) && ( y < 326 ) )
			{
				coreSurface::onDraw(displaySurface, scoreButtonSheet, 256,230, 0,0,125,96); //mouse over button
			}
			//If not
			else
			{
				//Set the button sprite
				coreSurface::onDraw(displaySurface, scoreButtonSheet, 257,230, 125,0,125,96);//mouse out of button
			}
			
			//If the mouse is over the load button
			if( ( x > 132 ) && ( x < 257 ) && ( y > 277 ) && ( y < 326 ) )
			{
				coreSurface::onDraw(displaySurface, loadButtonSheet, 131,278, 0,0,125,96); //mouse over button
			}
			//If not
			else
			{
				//Set the button sprite
				coreSurface::onDraw(displaySurface, loadButtonSheet, 132,277, 125,0,125,96);//mouse out of button
			}

			//If the mouse is over the start button
			if( ( x > 7 ) && ( x < 132 ) && ( y > 277 ) && ( y < 326 ) )
			{
				coreSurface::onDraw(displaySurface, startButtonSheet, 7,230, 0,0,125,96); //mouse over button
			}
			//If not
			else
			{
				//Set the button sprite
				coreSurface::onDraw(displaySurface, startButtonSheet, 7,230, 125,0,125,96);//mouse out of button
			}
		}

		//If a mouse button was pressed
		if(Event->type == SDL_MOUSEBUTTONDOWN)
		{
			//If the left mouse button was pressed
			if( Event->button.button == SDL_BUTTON_LEFT )
			{
				//Get the mouse offsets
				x = Event->button.x;
				y = Event->button.y;

				//If the mouse is over the options button
				if( ( x > 382 ) && ( x < 507 ) && ( y > 277 ) && ( y < 326 ) )
				{
					//go to options/instruction menu
					setMainMenu(false);
					setOptionsMenu(true);
				}
				//If the mouse is over the exit button
				if( ( x > 507 ) && ( x < 632 ) && ( y > 277 ) && ( y < 326 ) )
				{
					//Set the button sprite
					setMainMenu(false);
					isRunning = false;
				}
				//If the mouse is over the start button
				if( ( x > 7 ) && ( x < 132 ) && ( y > 277 ) && ( y < 326 ) )
				{
					return false;
				}

			}
		}
	}

	if(getOptionsMenu() == true)
	{
		//Draw the options menu to the screen
		coreSurface::onDraw(displaySurface, optionsMenu, 0,0);
		//Display default mouse out button for back to the main menu
		coreSurface::onDraw(displaySurface, backButtonSheet, 257,374, 125,0,125,96); 

		//If the mouse moved
		if(Event->type == SDL_MOUSEMOTION)
		{
			//Get the mouse offsets
			x = Event->motion.x;
			y = Event->motion.y;

			//If the mouse is over the back button
			if( ( x > 257 ) && ( x < 382 ) && ( y > 421 ) && ( y < 470 ) )
			{
				//Set the button sprite
				coreSurface::onDraw(displaySurface, backButtonSheet, 255,374, 0,0,125,96); // mouse over button
			}
			//If not
			else
			{
				//Set the button sprite
				coreSurface::onDraw(displaySurface, backButtonSheet, 257,374, 125,0,125,96); // mouse out button
			}
		}

		//If a mouse button was pressed
		if( Event->type == SDL_MOUSEBUTTONDOWN)
		{
			//If the left mouse button was pressed
			if( Event->button.button == SDL_BUTTON_LEFT )
			{
				//Get the mouse offsets
				x = Event->button.x;
				y = Event->button.y;

				//If the mouse is over the back button
				if( ( x > 257 ) && ( x < 382 ) && ( y > 421 ) && ( y < 470 ) )
				{
					//Set the button sprite
					setMainMenu(true);
					setOptionsMenu(false);
				}
			}
		}
	}

	//If a key was pressed
    if(Event->type == SDL_KEYDOWN)
    {
		//If 9 was pressed
        if(Event->key.keysym.sym == SDLK_9 )
        {
            //If there is no music playing
            if( Mix_PlayingMusic() == 0 )
            {
                //Play the music
				Mix_PlayMusic( music, -1 );
            }
            //If music is being played
            else
            {
                //If the music is paused
                if( Mix_PausedMusic() == 1 )
                {
                    //Resume the music
                    Mix_ResumeMusic();
                }
                //If the music is playing
                else
                {
                    //Pause the music
                    Mix_PauseMusic();
                }
            }
        }
        //If 0 was pressed
        else if(Event->key.keysym.sym == SDLK_0 )
        {
            //Stop the music
            Mix_HaltMusic();
        }
    }
		
	//If X is pressed on corner of screen, quit the window
	if(Event->type == SDL_QUIT) 
	{
		isRunning = false;    
    }

	//FLIP BACKBUFFER	
	SDL_Flip(displaySurface);

	return true;
}