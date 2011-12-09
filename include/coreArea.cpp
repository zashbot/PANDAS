#include "coreArea.h"

coreArea coreArea::areaControl;

coreArea::coreArea()
{
	areaSizeX = 0;
	areaSizeY = 0;
}

bool coreArea::onLoad(char* File)
{
	mapList.clear();

	FILE* fileHandle = fopen(File, "r");

	if(fileHandle == NULL)
	{
		fprintf(stderr, "\nFailed to open area file ");
		fprintf(stderr, File);
		return false;
	}
	char tilesetFile[255];
	
	fscanf(fileHandle, "%s\n", tilesetFile);
	if((surfaceTileset = coreSurface::onLoad(tilesetFile)) == false)
	{
		fclose(fileHandle);
		fprintf(stderr, "Failed to load tileset image ");
		fprintf(stderr, tilesetFile);
		return false;
	}
	coreSurface::Transparent(surfaceTileset, 255, 0, 255);
	
	char backgroundFile[255];
	fscanf(fileHandle, "%s\n", backgroundFile);
	if((mapBackground = coreSurface::onLoad(backgroundFile)) == false)
	{
		fclose(fileHandle);
		fprintf(stderr, "Failed to load background image ");
		fprintf(stderr, backgroundFile);
		return false;
	}


	fscanf(fileHandle, "%d\n", &areaSizeY);
	fscanf(fileHandle, "%d\n", &areaSizeX);
	for(int X = 0; X < areaSizeY; X++)
	{
		for(int Y = 0; Y < areaSizeX; Y++)
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

	coreSurface::onDraw(displaySurface, mapBackground, ((cameraX/3)-300), ((cameraY/3)-300));

	int firstID = -cameraX / mapWidth;
	firstID = firstID + ((-cameraY / mapHeight) * areaSizeX);

	for(int i = 0; i < 4; i++)
	{
		int ID = firstID + (((i / 2) * (areaSizeX)) + (i % 2));

		if (ID < 0 || ID >= mapList.size()) continue;

		int X = ((ID % areaSizeX) * mapWidth) + cameraX;
		int Y = ((ID / areaSizeX) * mapHeight) + cameraY;
		mapList[ID].onRender(displaySurface, X, Y);
	}
}

void coreArea::onCleanup()
{
	if(surfaceTileset)
		SDL_FreeSurface(surfaceTileset);
	mapList.clear();
}

coreMap* coreArea::getMap(int X, int Y)
{
	int MapWidth  = MAP_WIDTH * TILE_SIZE;
    int MapHeight = MAP_HEIGHT * TILE_SIZE;
 
    int ID = X / MapWidth;
        ID = ID + ((Y / MapHeight) * areaSizeY);
 
    if(ID < 0 || ID >= mapList.size()) {
        return NULL;
    }
 
    return &mapList[ID];
}

coreTile* coreArea::getTile(int X, int Y) {
    int MapWidth  = MAP_WIDTH * TILE_SIZE;
    int MapHeight = MAP_HEIGHT * TILE_SIZE;
 
    coreMap* map = getMap(X, Y);
 
    if(map == NULL) return NULL;
 
    X = X % MapWidth;
    Y = Y % MapHeight;
 
    return map->getTile(X, Y);
}