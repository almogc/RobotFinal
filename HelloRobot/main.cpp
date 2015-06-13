/*
 * main.c  pp
 *
 *  Created on: Jan 10, 2015
 *      Author: colman
 */

#include "lodepng.h"
#include "Globals.h"
#include "Map.h"
#include <iostream>
#include <fstream>


using namespace std;

std::vector<unsigned char> image; //the raw pixels
unsigned width, height;

void ReadParametersFile()
{
	string FileContent, FileVariable;
	ifstream infile;
	size_t Pos;
	Globals *pntGlobals;
	pntGlobals = pntGlobals->getInstance();

	infile.open ("parameters.txt");
	if (infile.is_open()) {
	while(!infile.eof())
        {
			getline(infile,FileContent);
			Pos = FileContent.find(": ");
			FileVariable = FileContent.substr(0,Pos);
			if (!FileVariable.compare("map"))
			{
				pntGlobals->mapLocation = FileContent.substr(Pos+2,FileContent.length());
				cout << pntGlobals->mapLocation << endl;
			}
			else if (!FileVariable.compare("startLocation"))
			{
				FileContent = FileContent.substr(Pos+2,FileContent.length());

				Pos = FileContent.find(" ");
				pntGlobals->StartLocation.Xpos = atoi(FileContent.substr(0,Pos).c_str());
				FileContent = FileContent.substr(Pos+1,FileContent.length());

				Pos = FileContent.find(" ");
				pntGlobals->StartLocation.Ypos = atoi(FileContent.substr(0,Pos).c_str());
				FileContent = FileContent.substr(Pos+1,FileContent.length());

				pntGlobals->StartLocation.Yaw = atoi(FileContent.substr(0,Pos-1).c_str());
			}
			else if (!FileVariable.compare("goal"))
			{
				FileContent = FileContent.substr(Pos+2,FileContent.length());

				Pos = FileContent.find(" ");
				pntGlobals->Goal.Xpos = atoi(FileContent.substr(0,Pos).c_str());
				FileContent = FileContent.substr(Pos+1,FileContent.length());

				pntGlobals->Goal.Ypos = atoi(FileContent.substr(0,Pos).c_str());
			}
			else if (!FileVariable.compare("robotSize"))
			{
				FileContent = FileContent.substr(Pos+2,FileContent.length());
				Pos = FileContent.find(" ");

				pntGlobals->RobotSize = atof(FileContent.substr(0,Pos).c_str());
			}
			else if (!FileVariable.compare("MapResolutionCM"))
			{
				pntGlobals->MapResolutionCM  = atof(FileContent.substr(Pos+2,FileContent.length()-1).c_str());
			}
			else if (!FileVariable.compare("GridResolutionCM"))
			{
				pntGlobals->GridResolutionCM  = atof(FileContent.substr(Pos+2,FileContent.length()-1).c_str());
			}
        }
	}
	infile.close();

}


int main() {
	const char* filename = "Maps/roboticLabMap.png";
	ReadParametersFile();

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
