/*
 * Manager.h
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Behaviors/Behavior.h"
#include "Globals.h"

class Manager {
protected:
	Behavior** _behaviors;
	Robot* _robot;
	Behavior* _currBehavior;

public:
	Manager(Robot* robot);
	void Start(Location* arr);
	virtual ~Manager();




};

#endif /* MANAGER_H_ */
