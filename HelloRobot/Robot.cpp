/*
 * robot.cpp
 *
 *  Created on: Jun 27, 2015
 *      Author: colman
 */

#include "Robot.h"
#include "ConfigurationManager.h"

using namespace std;


Robot::Robot(char* ip, int port){
	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	ConfigurationMGR *pntConfiguration;
	pntConfiguration = pntConfiguration->getInstance();

	_pp->SetMotorEnable(true);

	_pp->SetOdometry(pntConfiguration->StartLocation.Xpos/10,
			pntConfiguration->StartLocation.Ypos/10,
			pntConfiguration->StartLocation.Yaw/180*M_PI);




	int i;
	for(i=0;i<15;i++)
		_pc->Read();

	robotStartX = getXPos();
	robotStartY = getYPos();

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
	robot->read();
	double currYaw = robot->getYaw();
	double absOffsetOne;

	int side = 0;

	absOffsetOne = currYaw - dYaw;
	if(absOffsetOne < 0)
	{
		absOffsetOne += M_PI*2;
	}

	if(absOffsetOne < M_PI)
	{
		side = -1;
	}
	else
	{
		side = 1;
	}



	while(true)
	{
		robot->read();
		currYaw = robot->getYaw();
		robot->setSpeed(0.0,0.25*side);

		if(currYaw > dYaw - 0.06 && currYaw < dYaw + 0.06)
		{
			break;
		}

	}

}

void Robot::ChangeYawRobotPlayer(Robot* robot,double dYaw)
{
	robot->read();
	double currYaw = robot->getYaw();
	currYaw += M_PI;
	double absOffsetOne;

	int side = 0;

	absOffsetOne = currYaw - dYaw;
	if(absOffsetOne < 0)
	{
		absOffsetOne += M_PI*2;
	}

	if(absOffsetOne < M_PI)
	{
		side = -1;
	}
	else
	{
		side = 1;
	}



	while(true)
	{
		robot->read();
		currYaw = robot->getYaw();
		currYaw += M_PI;
		robot->setSpeed(0.0,0.25*side);

		if(currYaw > dYaw - 0.06 && currYaw < dYaw + 0.06)
		{
			robot->setSpeed(0.0,0.0);
			break;
		}

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
	robot->read();
	double radYaw = robot->getYaw();
	double locationX = robot->getXPos();
	double locationY = robot->getYPos();

	locationX += (cos(radYaw) * dCm);
	locationY += (sin(radYaw) * dCm);

	double currX = robot->getXPos();
	double currY = robot->getYPos();

	while(true)
	{
		if((currX > locationX - 0.05 && currX < locationX + 0.05)&&
				(currY > locationY- 0.05 && currX < locationX + 0.05))
		{
			robot->setSpeed(0.0,0.0);
			break;
		}

		robot->read();
		robot->setSpeed(0.15, 0.0);
		 currX = robot->getXPos();
		 currY = robot->getYPos();
		 cout << currX << endl;
	}

}


Robot::~Robot() {
delete _pc;
delete _pp;
delete _lp;
}
