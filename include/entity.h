#pragma once
#include <stack>
class Entity
{
protected:
	double pos_x, pos_y, vel_x, vel_y;
	int height, width;
	string image_path;
	bool motionEnabled, landed;
public:
	Entity(int h, int y, int img_p, bool m_e);
	//set methods
	void setPosition_x(double pos);
	void setPosition_y(double pos);
	void setVelocity_x(double vel);//|these set it
	void setVelocity_y(double vel);//|
	void changeVelocity_x(double vel);//|these change it by a value
	void changeVelocity_y(double vel);//|
	void swapMotion();
	void swapLandState();
	//get methods
	double getVelocity_x(){return vel_x;};
	double getVelocity_y(){return vel_y;};
	double getPosition_x(){return pos_x;};
	double getPosition_y(){return pos_y;};
	int getHeight(){return height;};
	int getWidth(){return width;};
	string getImagePath(){return image_path;};
	bool isMotionEnabled(){return motionEnabled;};
	bool isLanded(){return landed;};
	~Entity(void);
};

