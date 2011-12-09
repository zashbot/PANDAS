#include "coreApp.h"

void coreApp::onLoop() //calls onLoop on every entity in the entity list vector
{
	//system("cls");
	for(int i = 0; i < coreEntity::entityList.size(); i++)
	{
		if(!coreEntity::entityList[i]) continue; //skips the current iteration of the loop if the entity at that point is null for some reason. 

		coreEntity::entityList[i]->onLoop();
	}
	coreFPS::FPScounter.onLoop();

	//cout << coreFPS::FPScounter.getSpeedFactor() << "\n";
	//cout << Player.X << " " << Player.Y << "\n";
	//cout << coreCamera::cameraControl.getX() << " " << coreCamera::cameraControl.getY() << "\n";
}