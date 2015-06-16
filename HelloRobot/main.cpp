/*
 * main.c  pp
 *
 *  Created on: Jan 10, 2015
 *      Author: colman
 */

#include "lodepng.h"
#include "Map.h"
#include <iostream>
#include <fstream>


using namespace std;

std::vector<unsigned char> image; //the raw pixels
unsigned width, height;





int main() {
	const char* filename = "Maps/roboticLabMap.png";


	Map map;
	map.MakeGridFromImage(filename);





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
