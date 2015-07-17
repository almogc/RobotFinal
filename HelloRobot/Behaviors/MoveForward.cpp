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
	//double startX = 90;
	//double startY = 76;
	//double startYaw = 20;
	double deltaX = 0;
	double deltaY = 0;

	double oldX = 0;
	double oldY = 0;
	double oldYaw = _robot->getYaw();


	currX = _robot->getXPos();
	currY =_robot->getYPos();
//	currYaw = _robot->getYaw();

	deltaX = currX - waypoint.Xpos/10;
	deltaY = currY - waypoint.Ypos/10;


	double distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));


	currYaw = atan(deltaX/deltaY);
  	cout <<  " yaw " << currYaw << endl;

  	_robot->ChangeYawRobot(_robot,currYaw);

	//_robot->Drive(_robot,distance);
	//_robot->Drive(_robot,0.0);


	//	double radYaw = 20 / 180.0 * M_PI;

	//double locationX = (cos(radYaw) * distance);
	//double locationY = (sin(radYaw) * distance);






}

MoveForward::~MoveForward() {
}
