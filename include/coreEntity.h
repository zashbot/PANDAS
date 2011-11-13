#pragma once
#include <vector>
#include "coreArea.h"
#include "coreAnimation.h"
#include "coreFPS.h"
#include "coreCamera.h"
#include "coreSurface.h"

enum
{
	ENTITY_TYPE_GENERIC = 0,
	ENTITY_TYPE_PLAYER
};

enum
{
	ENTITY_FLAG_NONE = 0,
	ENTITY_FLAG_GRAVITY,
	ENTITY_FLAG_GHOST,
	ENTITY_FLAG_MAPONLY
};
	

class coreEntity
{
public:
	static std::vector<coreEntity*> entityList; //confused? see: http://www.cplusplus.com/doc/tutorial/classes2/#static

protected:
	coreAnimation animControl;
	SDL_Surface* entSurface;
public:
	float X, Y;
	int Width, Height;
	bool moveRight, moveLeft;
	int type;
	bool dead;
	int flags;
protected:
	float speedX, speedY;
	float accelX, accelY;
public:
	float maxSpeedX, maxSpeedY;
protected:
	int currentFrameCol, currentFrameRow;
	int colX;
	int colY;
	int colWidth;
	int colHeight;

public:
	coreEntity();
	virtual ~coreEntity();
public:
	virtual bool onLoad(char* File, int Width, int Height, int Maxframes, char* name);
	virtual void onLoop();
	virtual void onRender(SDL_Surface* displaySurface);
	virtual void onCleanup();
	virtual void onAnimate();
	virtual void onCollision(coreEntity* entity);
	
public:
	void onMove(float moveX, float moveY);
	void stopMove();

public:
	bool collides(int oX, int oY, int oW, int oH);
private:
    bool posValid(int NewX, int NewY);
 	bool posValidTile(coreTile* Tile);
    bool posValidEntity(coreEntity* Entity, int newX, int newY); 
};

class coreEntityCol
{
public: 
	static std::vector<coreEntityCol> entityColList;
	
	coreEntity* entityA;
	coreEntity* entityB;

	coreEntityCol();
};

