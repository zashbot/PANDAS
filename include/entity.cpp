#include "entity.h"


entity::entity(int h, int w, int img_p, bool m_e)
{
	height=h;
	width=w;
	image_path=img_p;
	motionEnabled=m_e;
	pos_x = pos_y = vel_x = vel_y = 0;
}


entity::~entity(void)
{
}
