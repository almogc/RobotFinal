/*
 * WayPointManager.cpp
 */

#include "WaypointsManager.h"
#include "ConfigurationManager.h"


#include <iostream>

using namespace std;

void WayPointsManager::createWaypoints(string route, Location* &arr)
{

	const int dirNum=8; // number of possible directions to go at any position
	static int dirX[dirNum]={-1, -1, 0, 1, 1, 1, 0, -1};
	static int dirY[dirNum]={0, 1, 1, 1, 0, -1, -1, -1};


	ConfigurationMGR *pntConfiguration;
	pntConfiguration = pntConfiguration->getInstance();

	if (route.length() > 0)
			{
				int counter = 0;
				int lastDirection = (int)(route.at(0)-'0');
				int direction;
				int nNumOfWayPoints = 0;
				arr = new Location[50];
				Location* tempArr;
				char c;
				int x = 0;
				int y = 0;

				cout << "start - X: " << pntConfiguration->StartLocation.Xpos << " Y: " << pntConfiguration->StartLocation.Ypos << endl;
				cout << "finish - X: " << pntConfiguration->Goal.Xpos << " Y: " << pntConfiguration->Goal.Ypos << endl;

				for (unsigned int i = 0; i < route.length(); i++)
				{
					c = route.at(i);
					direction = c-'0';

					if((counter == 0) || (lastDirection == direction && counter < 5))
					{
						counter ++;
					}
					else
					{

						arr[nNumOfWayPoints].Xpos = x;
						arr[nNumOfWayPoints].Ypos = y;
						lastDirection = direction;
						counter = 0;
						nNumOfWayPoints++;
						cout << "x: " << x << " y: " << y << endl;
					}

					//Swich X Y
					x += dirY[direction];
					y += dirX[direction];
				}
				cout << "x: " << x << " y: " << y << endl;
				cout << "a";

			}
			else
			{
				cout << "No route found";
				cout << endl;
			}


}
