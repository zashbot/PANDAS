#include <cstdlib>
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
using namespace std;
SDL_Surface *screen;

int main(int argc, char *argv[]) //you need these because SDL redefines main() in this way.
{
	int InitVideo(SDL_HWSURFACE);
	cin.get(); cin.get();
	return 1;
}

int InitVideo(Uint32 flags = SDL_DOUBLEBUF | SDL_FULLSCREEN, int s_width=640, int s_height=480) //will be changeable later using preload dialouge, do not assume these are static values when writing code
{
  // Load SDL
  if (SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_NOPARACHUTE /* for debugging */) != 0) {
    fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
    return false;
  }
  atexit(SDL_Quit); //cleans up nicely
 
  screen = SDL_SetVideoMode(s_width, s_height, 32, flags);
  if (screen == NULL) {
    fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
    return false;
  }
  return true;
}