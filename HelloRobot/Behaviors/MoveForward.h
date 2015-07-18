/*
 * MoveForward.h
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#ifndef MOVEFORWARD_H_
#define MOVEFORWARD_H_

#include "Behavior.h"
#include "../Globals.h"

class MoveForward: public Behavior {
public:

	MoveForward(Robot* robot);
	bool startCond();
	bool stopCond();
	void doAction(Location waypoint);
	virtual ~MoveForward();
};

#endif /* MOVEFORWARD_H_ */
