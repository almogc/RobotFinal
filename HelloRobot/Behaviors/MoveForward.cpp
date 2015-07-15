/*
 * MoveForward.cpp
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#include "MoveForward.h"

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

void MoveForward::doAction() {
	_robot->setSpeed(0.2,0.0);
}

MoveForward::~MoveForward() {
}
