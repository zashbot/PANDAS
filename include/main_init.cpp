#include <cstdlib>
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

SDL_Surface *screen;
int main(int argc, char *argv[])
{
	int InitVideo(SDL_HWSURFACE);
	system("pause");
	return 1;
}

int InitVideo(Uint32 flags = SDL_DOUBLEBUF | SDL_FULLSCREEN, int s_width=640, int s_height=480) 
{
  // Load SDL
  if (SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_NOPARACHUTE) != 0) {
    fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
    return false;
  }
  atexit(SDL_Quit);
 
  screen = SDL_SetVideoMode(s_width, s_height, 32, flags);
  if (screen == NULL) {
    fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
    return false;
  }
  return true;
}