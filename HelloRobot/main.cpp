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


using namespace std;



int main() {
	int** GridMap;
	int nGridWidth, nGridHight;

	Map map;
	map.MakeGridFromImage(GridMap,&nGridWidth, &nGridHight);

	cout << "Grid Width: " << nGridWidth << endl;
	cout << "Grid Hight: " << nGridHight << endl;
	cout << "place [5][6] is " << GridMap[5][6] << endl;

	ConfigurationMGR *pntConfiguration;
	pntConfiguration = pntConfiguration->getInstance();

	PathPlanner path;
	string route = path.AStarPathFind(pntConfiguration->StartLocation.Ypos,pntConfiguration->StartLocation.Xpos,
			pntConfiguration->Goal.Ypos,pntConfiguration->Goal.Xpos,GridMap, nGridHight, nGridWidth);

	path.PrintPath(GridMap,pntConfiguration->StartLocation.Ypos,pntConfiguration->StartLocation.Xpos, nGridHight, nGridWidth,route);


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

