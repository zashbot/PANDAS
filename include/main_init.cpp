
#include <cstdlib>
#include <sdl.h>
#include <SDL_mixer.h>
#include <iostream>
using namespace std;

SDL_Surface *screen;

int InitVideo(Uint32 flags = SDL_DOUBLEBUF | SDL_FULLSCREEN, int s_width=640, int s_height=480) //will be changeable later using preload dialouge, do not assume these are static values when writing code
{
  // Load SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
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

int main(int argc, char *argv[]) //you need these because SDL redefines main() in this way.
{
	if (InitVideo(SDL_DOUBLEBUF | SDL_SWSURFACE) == 0) {cin.get(); return false;} //loads sdl and gives the user a chance to see the error message
	
	SDL_Surface *image; SDL_Surface *temp;
	temp = SDL_LoadBMP("img/debug/image.bmp"); if (temp == NULL) { printf("Unable to load bitmap: %s\n", SDL_GetError()); return 1; }
	image = SDL_DisplayFormat(temp); SDL_FreeSurface(temp);
	SDL_Rect src, dest; //creates 2 SDL rectangle structs
	src.x = 0; src.y = 0; src.w = image->w; src.h = image->h;
	dest.x = 100; dest.y = 100; dest.w = image->w; dest.h = image->h;
	SDL_BlitSurface(image, &src, screen, &dest)	;  //loads the image onto the backbuffer
	SDL_Flip(screen); //flips the backbuffer to the screen, therefore displaying the image
	cout << "Image displayed \n";
	SDL_Delay(2500);
	return 1;
}

//testing commit from visual studio
//drew testing commits