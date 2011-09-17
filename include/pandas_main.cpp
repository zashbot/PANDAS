#include <SDL.h>
#include <SDL_mixer.h>
#include "App.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) //you need these because SDL redefines main() in this way.
{
	//you could put some sort of debugging options menu here
	
	App PANDAS;
	return PANDAS.onExecute();
} 