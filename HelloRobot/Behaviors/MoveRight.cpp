/*
 * MoveRight.cpp
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#include "MoveRight.h"


MoveRight::MoveRight(Robot* robot) :
	Behavior(robot) {
}

MoveRight::~MoveRight() {
}

bool MoveRight::startCond() {
	// Checks if there are obstacles on the right side of the robot
	for (int i = 0; i < 333; i++) {
		double dist = _robot->getLaserDistance(i);

		// There is an obstacle in front - we can't continue
		if (dist < 0.3)
			return false;
	}

	cout << "start true in right" << endl;
	return true;
}

bool MoveRight::stopCond() {
	// Checks if there are obstacles in front of the robot, if not we can stop turn
	for (int i = 240; i < 440; i++) {
		double dist = _robot->getLaserDistance(i);

		// There is an obstacle in front - we can't continue
		if (dist < 0.4) {
			cout << "return false in right" << endl;
			return false;
		}
	}

	cout << "return true in right" << endl;
	return true;
}

void MoveRight::doAction(Location waypoint) {
	_robot->setSpeed(0.0, -0.3);
}
