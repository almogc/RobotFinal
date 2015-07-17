/*
 * main.c  pp
 *
 *  Created on: Jan 10, 2015
 *      Author: colman
 */

#include "Map.h"
#include "ConfigurationManager.h"
#include "PathPlanner.h"
#include <iostream>
#include <fstream>
#include "Particle.h"
#include "Manager.h"
#include "WaypointsManager.h"
#include "Globals.h"

using namespace std;



int main() {
	int** GridMap;
	int nGridWidth, nGridHight;
	Location* locations;
	Map map;
	map.MakeGridFromImage(GridMap,&nGridWidth, &nGridHight);

	cout << "Grid Width: " << nGridWidth << endl;
	cout << "Grid Hight: " << nGridHight << endl;
	cout << "place [5][6] is " << GridMap[5][6] << endl;

	Particle* arr_particles[PARTICLE_NUM];

		for (int i = 0; i < PARTICLE_NUM; i++)
		{
			int x = rand() % (int)(nGridHight);
			int y = rand() % (int)(nGridHight);
			int yaw = rand() % (int)(ANGLES_NUM);
			if(GridMap[x][y]==0)
			{
				GridMap[x][y] = 5;

//				arr_particles[i] = new Particle(x, y, yaw, 1);
			}
			else
			{
				i--;
			}
		}

	ConfigurationMGR *pntConfiguration;
	pntConfiguration = pntConfiguration->getInstance();

	PathPlanner path;
	string route = path.AStarPathFind(pntConfiguration->StartLocation.Ypos,pntConfiguration->StartLocation.Xpos,
			pntConfiguration->Goal.Ypos,pntConfiguration->Goal.Xpos,GridMap, nGridHight, nGridWidth);

	path.PrintPath(GridMap,pntConfiguration->StartLocation.Ypos,pntConfiguration->StartLocation.Xpos, nGridHight, nGridWidth,route);

	WayPointsManager waypoint;
	waypoint.createWaypoints(route, locations);

	Robot robot("10.10.245.65",6665);
	Manager m(&robot);
	m.Start(locations);

	//robot.ChangeYawRobot(&robot,3.15);
	//robot.ChangeYawRobot(&robot,1.57);
	//robot.ChangeYawRobot(&robot,4.71);
	//robot.Drive(&robot,1);
	//robot.read();
	//cout << robot.getXPos() << endl;
	//cout << robot.getYPos() << endl;
	//robot.Drive(&robot,0.5);


//	PlayerClient pc("localhost", 6665);
//	LaserProxy lp(&pc);
//	Position2dProxy pp(&pc);

//	pp.SetMotorEnable(true);
//	while (true) {

//		pc.Read();

//		if (lp[333] < 0.8)
//			pp.SetSpeed(0.0, 0.3);
//		else
//			pp.SetSpeed(0.8, 0.0);

//	}

//		if (lp[333] < 0.8)
//			pp.SetSpeed(0.0, 0.3);
//		else
//			pp.SetSpeed(0.8, 0.0);

//	}

	return 0;

}

