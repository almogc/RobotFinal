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

void Robot::ChangeYawRobot(Robot* robot,double dYaw)
{
	for(int i=1; i<10;i++)
		{
			robot->read();
			robot->setSpeed(0.0, dYaw);
		}
}

void Robot::ChangeDegreeRobot(Robot* robot,double dDegree)
{
	for(int i=1; i<20;i++)
		{
			robot->read();
			robot->setSpeed(0.0, (dDegree / 180) * M_PI);
		}
}

void Robot::Drive(Robot* robot,double dCm)
{
	for(int i=1; i<10;i++)
		{
			robot->read();
			robot->setSpeed(dCm, 0.0);
		}
}


Robot::~Robot() {
delete _pc;
delete _pp;
delete _lp;
}
