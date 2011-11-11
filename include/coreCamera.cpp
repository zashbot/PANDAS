#include "coreCamera.h"

coreCamera coreCamera::cameraControl; //declare the static object

coreCamera::coreCamera()
{
	X = Y = 0;

	targetX = targetY = NULL;

	targetMode = TARGET_MODE_NORMAL;
}

void coreCamera::onMove(int moveX, int moveY)
{
	X += moveX;
	Y += moveY;
}

int coreCamera::getX()
{
	if(targetX != NULL)
	{
		if(targetMode == TARGET_MODE_CENTER)
		{
			return *targetX - (WWIDTH / 2);
		}

		return *targetX;
	}
	return X;
}

int coreCamera::getY()
{
	if(targetY != NULL)
	{
		if(targetMode == TARGET_MODE_CENTER)
		{
			return *targetY - (WWIDTH / 2);
		}

		return *targetY;
	}
	return Y;
}

void coreCamera::setPos(int X, int Y)
{
	this->X = X;
	this->Y = Y;
}

void coreCamera::setTarget(int* X, int* Y)
{
	targetX = X;
	targetY = Y;
}