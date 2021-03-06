/*
 * MoveForward.cpp
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#include "MoveForward.h"
#include "math.h"
#include "../ConfigurationManager.h"
#include "../LocalizationManager.h"

MoveForward::MoveForward(Robot* robot) :Behavior(robot){

}

bool MoveForward::startCond() {
	// Checks if there are obstacles in front of the robot
	for(int i=240; i<440;i++)
	{
		double dist = _robot->getLaserDistance(i);

		// There is an obstacle in front - we can't continue
		if(dist < 0.3)
			return false;
	}

	cout << "start true in right" << endl;
	return true;
}
bool MoveForward::stopCond() {
	// Checks if there are obstacles in front of the robot
	for(int i=240; i<440;i++)
	{
		double dist = _robot->getLaserDistance(i);

		// There is an obstacle in front - we should stop!
		if(dist < 0.4)
			return true;
	}

	return false;
}

void MoveForward::doAction(Location waypoint) {

	//LocalizationManager *local;
//	local = local->getInstance();

	ConfigurationMGR *pntConfiguration;
		pntConfiguration = pntConfiguration->getInstance();


	for (int i=0; i<5 ; i++)
	{
		_robot->read();
	}

	double currX;
	double currY;
	double currYaw;
	double deltaX = 0;
	double deltaY = 0;

	// get the position from the robot and subs the start position to check the delta
	currX = _robot->getXPos() - _robot->robotStartX;
	currY =_robot->getYPos() - _robot->robotStartY;


//	local->getInstance()->initParticle(int(currX*10 + pntConfiguration->StartLocation.Xpos),
	//							int(currY*10 + pntConfiguration->StartLocation.Ypos));


	// calculate the delta we have to do in each coordinate until the next waypoint
	deltaX = waypoint.Xpos/10 - currX;
	deltaY = waypoint.Ypos/10 - currY;



	// calculate the distance and the angel we need
	double distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
	currYaw = atan(abs(deltaX/deltaY));

	if(deltaX <= 0)
	{
		if(deltaY <=0)
		{
			currYaw = M_PI - currYaw;
		}
		else
		{

		}
	}
	else
	{
		if(deltaY <=0)
		{
			currYaw += M_PI;
		}
		else
		{
			currYaw = 2*M_PI -currYaw;
		}
	}


	currYaw += 1.57;

	if (currYaw >= 2*M_PI)
	{
		currYaw -= 2*M_PI;
	}

	if(currYaw < 0)
	{
		currYaw += 2*M_PI;
	}

//	local->getInstance()->UpdateBel(deltaX*10,deltaY*10,currYaw,_robot);
//	Location loc;
//	loc = local->getInstance()->GetHigeBel();


	cout << "Yaw : " << currYaw << " distance: " << distance << endl;
  	_robot->ChangeYawRobot(_robot,currYaw);
 	_robot->Drive(_robot,distance);



}

MoveForward::~MoveForward() {
}
