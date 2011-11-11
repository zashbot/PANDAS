#include "coreMap.h"

coreMap::coreMap()
{
	surfaceTileset = NULL;
}

bool coreMap::onLoad(char* File)
{
	tileList.clear();

	FILE* fileHandle = fopen(File, "r"); //opens "File"
	if(fileHandle == NULL)
	{
		fprintf(stderr, "could not open ", File, ". Probably missing from directory");
		return false;
	}

	for(int Y = 0; Y < MAP_HEIGHT; Y++)
	{
		for(int X = 0; X < MAP_WIDTH; X++)
		{
			coreTile tempTile;
			fscanf(fileHandle, "%d:%d", &tempTile.tileID, &tempTile.typeID); //confused? see: http://www.cplusplus.com/reference/clibrary/cstdio/fscanf/ still confused? ask Petur.
			tileList.push_back(tempTile);
		}
		fscanf(fileHandle, "\n"); //new line
	}
	fclose(fileHandle);
	return true;
}

void coreMap::onRender(SDL_Surface* displaySurface, int MapX, int MapY)
{
	if(surfaceTileset==NULL)
	{
		fprintf(stderr, "could not render map region because the tileset was NULL.");
		return;
	}

	int tilesetWidth = surfaceTileset->w / TILE_SIZE;
	int tilesetHeight = surfaceTileset->h / TILE_SIZE;

	int ID = 0;

	for(int Y = 0; Y < MAP_HEIGHT; Y++)
	{
		for(int X = 0; X < MAP_WIDTH; X++)
		{
			if(tileList[ID].typeID == TILE_TYPE_NONE)
			{
				ID++;
				continue; //goes on to the next iteration without doing the stuff below
			}
			int tX = MapX + (X * TILE_SIZE);
			int tY = MapY + (Y * TILE_SIZE);

			int tileSetX = (tileList[ID].tileID % tilesetWidth) * TILE_SIZE; 
			int tileSetY = (tileList[ID].tileID / tilesetWidth) * TILE_SIZE;

			coreSurface::onDraw(displaySurface, surfaceTileset, tX, tY, tileSetX, tileSetY, TILE_SIZE, TILE_SIZE);
			ID++;
		}
	}
}