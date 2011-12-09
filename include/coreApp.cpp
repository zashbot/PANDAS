#include "coreApp.h"


coreApp::coreApp()
{
	displaySurface = NULL;
	music = NULL;
	isRunning = true;
	gameMenu = true;
}

bool coreApp::onInit()
{
	//Load SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return false;
	}
		
	displaySurface = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_DOUBLEBUF | SDL_HWSURFACE);
	if (displaySurface == NULL) 
	{
		fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
		return false;
	}
	
	//Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
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
	
	if(coreArea::areaControl.onLoad("./maps/1.area") == false)
	{
		return false;
		fprintf(stderr, "Unable to load map");
	}
	
	if(Player.onLoad("./img/panda.bmp", 64, 64, 7, "test player") == false)
	{
		//error message here
		return false;
	}


	coreEntity::entityList.push_back(&Player);

	coreCamera::cameraControl.targetMode = TARGET_MODE_CENTER;
	coreCamera::cameraControl.setTarget(&Player.X, &Player.Y);

	SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);
	return true;
}

void coreApp::onCleanup()
{
	for(int i = 0; i < coreEntity::entityList.size(); i++) //cleans up all entities //ignore compiler warning here
	{
		if(!coreEntity::entityList[i]) continue; //skips the current iteration of the loop if the entity at that point is null for some reason. 

		coreEntity::entityList[i]->onCleanup();
	}
	coreEntity::entityList.clear();
	coreArea::areaControl.onCleanup();
	//coreMenu::onCleanup(); //Doesn't like this "illegal call of non-static member function"
	SDL_FreeSurface(displaySurface); //frees the screen from RAM
    Mix_FreeMusic( music ); //Free the music
    Mix_CloseAudio(); //Quit SDL_mixer
	SDL_Quit(); //quits SDL nicely
}

int coreApp::onExecute()
{
	SDL_Event Event;
	if(onInit() == false)
	{
		return -1;
	}
	if(menu.onInitialize() == false)
	{
		return -1;
	}
	
	//displaySurface = SDL_SetVideoMode(1000, 750, 32, SDL_DOUBLEBUF | SDL_HWSURFACE);
	
	while(isRunning && menu.getIsRunning() == true)
	{
		while(SDL_PollEvent(&Event))
		{
			gameMenu = menu.displayGameMenu(displaySurface, &Event); //Complains about event not being initialized
			SDL_Delay(1);
			//while(gameMenu)
			//{
			//	menu.displayGameMenu(displaySurface, &Event); //Complains about event not being initialized
			//	//gameMenu = menu.displayGameMenu(displaySurface, &Event); //Complains about event not being initialized
			//}	
		}

		while(gameMenu == false && isRunning)
		{
			//menu.onCleanup();
			
			while(SDL_PollEvent(&Event))
			{
				onEvent(&Event);
			}
			
			/*if(gameMenu == false)
			{*/
				onLoop();
				onRender();
				SDL_Delay(1);
			//}
		}
	}
	onCleanup();
	return 0;
}

