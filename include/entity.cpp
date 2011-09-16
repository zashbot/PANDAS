#include "entity.h"


Entity::Entity(int h, int w, int img_p, bool m_e)
{
	height=h;
	width=w;
	image_path=img_p;
	motionEnabled=m_e;
	pos_x = pos_y = vel_x = vel_y = 0;
}

void Entity::setPosition_x(double pos)
{
	pos_x = pos;
}

void Entity::setPosition_y(double pos)
{
	pos_y = pos;
}

void Entity::setVelocity_x(double vel)
{
	vel_x = vel;
}

void Entity::setVelocity_y(double vel)
{
	vel_y = vel;
}

void Entity::changeVelocity_x(double vel)
{
	vel_x = vel_x + vel;
}

void Entity::changeVelocity_y(double vel)
{
	vel_y = vel_y + vel;
}

void Entity::swapLandState()
{
	if(landed == true)
		landed = false;
	else
		landed = true;
}

void Entity::swapMotion()
{
	if(motionEnabled == true)
		motionEnabled = false;
	else
		motionEnabled = true;
}

Entity::~Entity(void)
{
}
