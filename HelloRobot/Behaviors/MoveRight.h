/*
 * MoveRight.h
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#ifndef MOVERIGHT_H_
#define MOVERIGHT_H_

#include "Behavior.h"
#include "../Globals.h"

class MoveRight:public Behavior{
public:
	MoveRight(Robot* robot);
	bool startCond();
	bool stopCond();
	void doAction(Location waypoint);
	virtual ~MoveRight();
};

#endif /* MOVERIGHT_H_ */
