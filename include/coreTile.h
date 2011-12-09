#pragma once
#include "define.h"

enum //sets these variables in increments of 1. confused? see: http://www.cplusplus.com/doc/tutorial/other_data_types/#enum
{
	TILE_TYPE_NONE = 0,
	TILE_TYPE_NORMAL, //=1
	TILE_TYPE_BLOCK //=2 etc.
};

class coreTile
{
public:
	int tileID;
	int typeID;
public:
	coreTile();
};