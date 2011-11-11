#include "coreArea.h"

coreArea coreArea::areaControl;

coreArea::coreArea()
{
	areaSize = 0;
}

bool coreArea::onLoad(char* File)
{
	mapList.clear();

	FILE* fileHandle = fopen(File, "r");

	if(fileHandle == NULL)
	{
		fprintf(stderr, "Failed to open area file ", File);
		return false;
	}
	char tilesetFile[255];

	fscanf(fileHandle, "%s\n", tilesetFile);
	if((surfaceTileset = coreSurface::onLoad(tilesetFile)) == false)
	{
		fclose(fileHandle);
		fprintf(stderr, "Failed to load tileset image ", tilesetFile);
		return false;
	}

	fscanf(fileHandle, "%d\n", &areaSize);
	for(int X = 0; X < areaSize; X++)
	{
		for(int Y = 0; Y < areaSize; Y++)
		{
			char mapFile[255];
			fscanf(fileHandle, "%s ", mapFile);
			coreMap tempMap;
			if((tempMap.onLoad(mapFile))==false)
			{
				fclose(fileHandle);
				fprintf(stderr, "Failed to load map file ", mapFile);
				return false;
			}
			tempMap.surfaceTileset = surfaceTileset;
			mapList.push_back(tempMap);
		}
		fscanf(fileHandle, "\n");
	}
	fclose(fileHandle);
	return true;
}

void coreArea::onRender(SDL_Surface* displaySurface, int cameraX, int cameraY)
{
	int mapWidth =  MAP_WIDTH * TILE_SIZE;
	int mapHeight = MAP_HEIGHT * TILE_SIZE;

	int firstID = -cameraX / mapWidth;
	firstID = firstID + ((-cameraY / mapHeight) * areaSize);

	for(int i = 0; i < 4; i++)
	{
		int ID = firstID + ((i / 2) * areaSize) + (i % 2);

		if (ID < 0 || ID >= mapList.size()) continue;

		int X = ((ID % areaSize) * mapWidth) + cameraX;
		int Y = ((ID / areaSize) * mapHeight) + cameraY;
		mapList[ID].onRender(displaySurface, X, Y);
	}
}

void coreArea::onCleanup()
{
	if(surfaceTileset)
		SDL_FreeSurface(surfaceTileset);
	mapList.clear();
}