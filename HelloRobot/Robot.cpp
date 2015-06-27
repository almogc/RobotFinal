/*
 * robot.cpp
 *
 *  Created on: Jun 27, 2015
 *      Author: colman
 */

#include "Robot.h"

using namespace std;


Robot::Robot(char* ip, int port){
	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	_pp->SetMotorEnable(true);
	int i;
	for(i=0;i<15;i++)
		_pc->Read();
}
void Robot::read()
{
	_pc->Read();
}
void Robot::setSpeed(float speed, float angularSpeed)
{
	_pp->SetSpeed(speed,angularSpeed);
}

double Robot::getLaserDistance(int index)
{
	return (*_lp)[index];
}

double Robot::getXPos()
{
	return _pp->GetXPos();
}

double Robot::getYPos()
{
	return _pp->GetYPos();
}

double Robot::getYaw()
{
	return _pp->GetYaw();
}

Robot::~Robot() {
delete _pc;
delete _pp;
delete _lp;
}
