/*
 * Behavior.cpp
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#include "Behavior.h"

Behavior::Behavior(Robot* robot) {
	_next = 0;
	_behaviorsCount = 0;
	_robot = robot;
}

Behavior* Behavior::addNext(Behavior* behavior)
{
	int i;
	Behavior** tmp = new Behavior*[_behaviorsCount+1];
	if(!tmp)
		return 0;
	for(i=0;i<_behaviorsCount;i++)
		tmp[i] = _next[i];
	tmp[i] = behavior;
	delete []_next;
	_next=tmp;
	_behaviorsCount++;
	return this;
}
Behavior* Behavior::selectNext()
{
	int i;
	for(i=0;i<_behaviorsCount;i++)
		if(_next[i]->startCond())
			return _next[i];

	cout << "next is NULL!!!" << endl;
	return 0;
}

Behavior::~Behavior() {
	delete [] _next;
}
