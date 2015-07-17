/*
 * robot.h
 *
 *  Created on: Jun 27, 2015
 *      Author: colman
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <libplayerc++/playerc++.h>
using namespace std;
using namespace PlayerCc;


class Robot {
	PlayerClient* _pc;
	Position2dProxy* _pp;
	LaserProxy* _lp;
public:
	Robot(char* ip, int port);
	void read();
	void setSpeed(float speed, float angularSpeed);
	double getLaserDistance(int index);
	double getXPos();
	double getYPos();
	double getYaw();
	virtual ~Robot();
	static void ChangeYawRobotPlayer(Robot* robot,double dYaw);
	static void ChangeYawRobot(Robot* robot,double dYaw);
	static void ChangeDegreeRobot(Robot* robot,double dDegree);
	static void Drive(Robot* robot,double dCm);

};

#endif /* ROBOT_H_ */
