/*
 * MoveForward.cpp
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#include "MoveForward.h"
#include "math.h"

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

	_robot->read();

	double currX;
	double currY;
	double currYaw;
	double deltaX = 0;
	double deltaY = 0;

	// get the position from the robot and subs the start position to check the delta
	currX = _robot->getXPos() - _robot->robotStartX;
	currY =_robot->getYPos() - _robot->robotStartY;

	// calculate the delta we have to do in each coordinate until the next waypoint
	deltaX = currX - waypoint.Xpos/10;
	deltaY = waypoint.Ypos/10 - currY;

	// calculate the distance and the angel we need
	double distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
	currYaw = (atan(deltaX/deltaY) + 1.57);

	if (currYaw >= 2*M_PI)
	{
		currYaw -= 2*M_PI;
	}

  	_robot->ChangeYawRobot(_robot,currYaw);
 	_robot->Drive(_robot,distance);

}

MoveForward::~MoveForward() {
}
