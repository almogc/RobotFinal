/*
 * Behavior.h
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#ifndef BEHAVIOR_H_
#define BEHAVIOR_H_

#include "../Robot.h"

class Behavior {
public:
	Behavior** _next;
		int _behaviorsCount;
	protected:
		Robot* _robot;
	public:
		Behavior(Robot* robot);
		virtual bool startCond() = 0;
		virtual bool stopCond() = 0;
		virtual void doAction() = 0;
		Behavior* addNext(Behavior* beh);
		Behavior* selectNext();
		virtual ~Behavior();
};

#endif /* BEHAVIOR_H_ */
