#include "coreEntity.h"

std::vector<coreEntity*> coreEntity::entityList; //declaring static member variable
std::vector<coreEntityCol> coreEntityCol::entityColList;

coreEntity::coreEntity()
{
	entSurface = NULL;
 
    X = 0;
    Y = 0;
 
    Width     = 0;
    Height     = 0;
 
    moveLeft  = false;
    moveRight = false;
 
    type =     ENTITY_TYPE_GENERIC;
 
    dead = false;
    flags = ENTITY_FLAG_GRAVITY;
 
    speedX = 0;
    speedY = 0;
 
    accelX = 0;
    accelY = 0;
 
    maxSpeedX = 20;
    maxSpeedY = 40;
 
    currentFrameCol = 0;
    currentFrameRow = 0;
 
    colX = 0;
    colY = 0;
 
    colWidth  = 0;
    colHeight = 0;


}
coreEntity::~coreEntity()
{
	//does nothing unless entity has dynamically allocated variables
}

bool coreEntity::onLoad(char* File, int Width, int Height, int Maxframes, char* name)
{
	if((entSurface = coreSurface::onLoad(File)) == NULL)
	{
		fprintf(stderr, "Unable to initialize loading of entity's texture, reason: ", SDL_GetError());
	}
	coreSurface::Transparent(entSurface, 255, 0, 255);
	
	this->Height = Height;
	this->Width = Width;
	animControl.maxFrames = Maxframes;
	return true;
}

void coreEntity::onLoop()
{
	if(moveLeft == false && moveRight == false) {
        stopMove();
    }
 
    if(moveLeft) {
        accelX = -0.5;
    }else
 
    if(moveRight) {
        accelX = 0.5;
    }
 
    if(flags & ENTITY_FLAG_GRAVITY) {
        accelY = 0.75f;
    }
 
    speedX += accelX * coreFPS::FPScounter.getSpeedFactor();
    speedY += accelY * coreFPS::FPScounter.getSpeedFactor();
 
    if(speedX > maxSpeedX)  speedX =  maxSpeedX;
    if(speedX < -maxSpeedX) speedX = -maxSpeedX;
    if(speedY > maxSpeedY)  speedY =  maxSpeedY;
    if(speedY < -maxSpeedY) speedY = -maxSpeedY;
	
    this -> onAnimate();
    this -> onMove(speedX, speedY);
}

void coreEntity::onRender(SDL_Surface* displaySurface)
{
	if(entSurface == NULL)
	{
		fprintf(stderr, "Entity tried to draw itself with no surface loaded");
		return;
	}
	if(displaySurface == NULL)
	{
		fprintf(stderr, "Entity tried to draw itself to a NULL screen pointer");
		return;
	}
	coreSurface::onDraw(displaySurface, entSurface, X - coreCamera::cameraControl.getX(), Y - coreCamera::cameraControl.getY(), currentFrameCol * Width, (currentFrameRow + animControl.getCurrentFrame()) * Height, Width, Height);
}

void coreEntity::onCleanup()
{
	if(entSurface)
	{
		SDL_FreeSurface(entSurface);
	}
	entSurface = NULL;
}

void coreEntity::onAnimate()
{
	if(moveLeft)
	{
		currentFrameCol = 1;
	}
	else if(moveRight)
	{
		currentFrameCol = 0;
	}
	animControl.onAnimate();
}

void coreEntity::onCollision(coreEntity* entity)
{

}

void coreEntity::onMove(float moveX, float moveY)
{
	if(moveX == 0 && moveY == 0) return;
 
    double NewX = 0;
    double NewY = 0;
 
    moveX *= coreFPS::FPScounter.getSpeedFactor();
    moveY *= coreFPS::FPScounter.getSpeedFactor();
 
    if(moveX != 0) {
        if(moveX >= 0)     NewX =  coreFPS::FPScounter.getSpeedFactor();
        else             NewX = -coreFPS::FPScounter.getSpeedFactor();
    }
 
    if(moveY != 0) {
        if(moveY >= 0)     NewY =  coreFPS::FPScounter.getSpeedFactor();
        else             NewY = -coreFPS::FPScounter.getSpeedFactor();
    }
 
    while(true) {
        if(flags & ENTITY_FLAG_GHOST) {
            posValid((int)(X + NewX), (int)(Y + NewY)); //We don't care about collisions, but we need to send events to other entities
 
            X += NewX;
            Y += NewY;
        }else{
            if(posValid((int)(X + NewX), (int)(Y))) {
                X += NewX;
            }else{
                speedX = 0;
            }
 
            if(posValid((int)(X), (int)(Y + NewY))) {
                Y += NewY;
            }else{
                speedY = 0;
            }
        }
 
        moveX += -NewX;
        moveY += -NewY;
 
        if(NewX > 0 && moveX <= 0) NewX = 0;
        if(NewX < 0 && moveX >= 0) NewX = 0;
 
        if(NewY > 0 && moveY <= 0) NewY = 0;
        if(NewY < 0 && moveY >= 0) NewY = 0;
 
        if(moveX == 0) NewX = 0;
        if(moveY == 0) NewY = 0;
 
        if(moveX == 0 && moveY     == 0)     break;
        if(NewX  == 0 && NewY     == 0)     break;
    }
}

void coreEntity::stopMove()
{
	if(speedX > 0)
		accelX = -1;
	if(speedX < 0)
		accelX = 1;
	if(speedX < 2.0f && speedX > -2.0f) 
	{
        accelX = 0;
        speedX = 0;
	}
}

bool coreEntity::collides(int oX, int oY, int oW, int oH)
{
	int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
 
    int tX = (int)X + colX;
    int tY = (int)Y + colY;
 
    left1 = tX;
    left2 = oX;
 
    right1 = left1 + Width - 1 - colWidth;
    right2 = oX + oW - 1;
 
    top1 = tY;
    top2 = oY;
 
    bottom1 = top1 + Height - 1 - colHeight;
    bottom2 = oY + oH - 1;
 
 
    if (bottom1 < top2) return false;
    if (top1 > bottom2) return false;
 
    if (right1 < left2) return false;
    if (left1 > right2) return false;
 
    return true;
}

bool coreEntity::posValid(int NewX, int NewY) 
{
    bool Return = true;
 
    int StartX     = (NewX + colX) / TILE_SIZE;
    int StartY     = (NewY + colY) / TILE_SIZE;
 
    int EndX    = ((NewX + colX) + Width - colWidth - 1)         / TILE_SIZE;
    int EndY    = ((NewY + colY) + Height - colHeight - 1)    / TILE_SIZE;
 
    for(int iY = StartY;iY <= EndY;iY++) {
        for(int iX = StartX;iX <= EndX;iX++) {
            coreTile* Tile = coreArea::areaControl.getTile(iX * TILE_SIZE, iY * TILE_SIZE);
 
            if(posValidTile(Tile) == false) {
                Return = false;
            }
        }
    }
 
    if(flags & ENTITY_FLAG_MAPONLY) {
    }else{
        for(int i = 0;i < entityList.size();i++) {
            if(posValidEntity(entityList[i], NewX, NewY) == false) {
                Return = false;
            }
        }
    }
 
    return Return;
}

bool coreEntity::posValidTile(coreTile* Tile) {
    if(Tile == NULL) {
        return true;
    }
 
    if(Tile->typeID == TILE_TYPE_BLOCK) {
        return false;
    }
 
    return true;
}

bool coreEntity::posValidEntity(coreEntity* Entity, int NewX, int NewY)
{
	if(this != Entity && Entity != NULL && Entity->dead == false &&
        Entity->flags ^ ENTITY_FLAG_MAPONLY &&
        Entity->collides(NewX + colX, NewY + colY, Width - colWidth - 1, Height - colHeight - 1) == true) {
 
        coreEntityCol entityCol;
 
        entityCol.entityA = this;
        entityCol.entityB = Entity;
 
        coreEntityCol::entityColList.push_back(entityCol);
 
        return false;
    }
 
    return true;
}

coreEntityCol::coreEntityCol()
{
}

