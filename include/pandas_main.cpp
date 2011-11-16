#include <SDL.h>
#include <SDL_mixer.h>
#include "coreApp.h"
#include "coreSurface.h"
#include <string>
using namespace std;

int main(int argc, char *argv[]) //you need these because SDL redefines main() in this way.
{
	//you could put some sort of debugging options menu here
	int exitCode = 0;
	coreApp pandas;
	return pandas.onExecute();
	printf("\n");
	system("pause");
	return exitCode;
	//d
} 