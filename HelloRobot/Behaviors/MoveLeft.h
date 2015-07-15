/*
 * MoveLeft.h
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#ifndef MOVELEFT_H_
#define MOVELEFT_H_

#include "Behavior.h"

class MoveLeft:public Behavior {
public:
	MoveLeft(Robot* robot);
	bool startCond();
		bool stopCond();
		void doAction();
	virtual ~MoveLeft();
};

#endif /* MOVELEFT_H_ */
