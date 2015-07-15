/*
 * Manager.h
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Behaviors/Behavior.h"


class Manager {
protected:
	Behavior** _behaviors;
	Robot* _robot;
	Behavior* _currBehavior;

public:
	Manager(Robot* robot);
	void Start();
	virtual ~Manager();
};

#endif /* MANAGER_H_ */
