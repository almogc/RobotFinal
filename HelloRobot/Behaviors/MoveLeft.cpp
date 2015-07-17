/*
 * MoveLeft.cpp
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#include "MoveLeft.h"

MoveLeft::MoveLeft(Robot* robot) :Behavior(robot){
}

MoveLeft::~MoveLeft() {
}

bool MoveLeft::startCond() {
	// Checks if there are obstacles on the left side of the robot
	for(int i=335; i<667;i++)
	{
		double dist = _robot->getLaserDistance(i);

		// There is an obstacle in front - we can't continue
		if(dist < 0.3)
			return false;
	}

	cout << "start true in right" << endl;
	return true;
}

bool MoveLeft::stopCond() {
	// Checks if there are obstacles in front of the robot, if not we can stop turn
	for(int i=240; i<440;i++)
	{
		double dist = _robot->getLaserDistance(i);

		// There is an obstacle in front - we can't continue
		if (dist < 0.4)
		{
			cout << "return false in left" << endl;
			return false;
		}
	}
	cout << "return true in left " << endl;
	return true;
}

void MoveLeft::doAction(Location waypoint) {
	_robot->setSpeed(0.0,0.5);
}
