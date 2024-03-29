#pragma once

#include <SDL.h>
#include "define.h"

enum
{
	TARGET_MODE_NORMAL = 0,
	TARGET_MODE_CENTER
};

class coreCamera
{
public:
	static coreCamera cameraControl;

private:
	int X;
	int Y;
	float* targetX;
	float* targetY;

public:
	int targetMode;

	coreCamera();
	
	void onMove(int moveX, int moveY);

	int getX();
	int getY();

	void setPos(int X, int Y);
	void setTarget(float* X, float* Y);
};