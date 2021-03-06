/*
 * Manager.cpp
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#include "Manager.h"
#include "Behaviors/MoveForward.h"
#include "Behaviors/MoveRight.h"
#include "Behaviors/MoveLeft.h"


Manager::Manager(Robot* robot) {
	_robot = robot;
	_behaviors = new Behavior*[3];

	//Creating the behaviors
	_behaviors[0] = new MoveForward(_robot);
	_behaviors[1] = new MoveLeft(_robot);
	_behaviors[2] = new MoveRight(_robot);

	//Connecting behaviors
	_behaviors[0]->addNext(_behaviors[1])->addNext(_behaviors[2]);
	_behaviors[1]->addNext(_behaviors[0]);
	_behaviors[2]->addNext(_behaviors[0]);

	_currBehavior = _behaviors[0];


}

void Manager::Start(Location* arr){
		_robot->read();
		_robot->read();
		_robot->read();

		double currX;
		double currY;
		double currYaw;
		double oldX = 0;
		double oldY = 0;
		double oldYaw = 0;
		int i=0;

		while ((_currBehavior != 0))
		{
			if(arr[i].Xpos == 0)
			{
				break;
			}

			while(!_currBehavior->stopCond())
			{
				_currBehavior->doAction(arr[i]);
				_robot->read();
				_robot->read();

				i++;

				currX = _robot->getXPos();
				currY = _robot->getYPos();
				currYaw = _robot->getYaw();

				// printing robot's location
				cout << "Robot location: " << currX << ", " << currY << ", " << currYaw << endl;

				// Updating particles and printing the map


				oldX = currX;
				oldY = currY;
				oldYaw = currYaw;
			}
			_currBehavior = _currBehavior->selectNext();
		}
}

Manager::~Manager() {
	delete[] _behaviors;
}
