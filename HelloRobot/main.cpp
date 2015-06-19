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
	bool** GridMap;
	int nGridWidth, nGridHight;

	Map map;
	map.MakeGridFromImage(GridMap,&nGridWidth, &nGridHight);

	cout << "Grid Width: " << nGridWidth << endl;
	cout << "Grid Hight: " << nGridHight << endl;
	cout << "place [5][6] is " << GridMap[5][6];

	for (int y = 0; y < nGridWidth; y++)
	{
		for (int x = 0; x < nGridHight; x++)
		{
			cout << GridMap[x][y];
		}
		cout << endl;
	}

	ConfigurationMGR *pntConfiguration;
	pntConfiguration = pntConfiguration->getInstance();


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

