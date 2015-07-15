/*
 * WayPointManager.cpp
 */

#include "WaypointsManager.h"
#include "ConfigurationManager.h"
#include "PathPlanner.h"

#include <iostream>

using namespace std;

void WayPointsManager::createWaypoints(string route, Location* arr)
{
// berman
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
				unsigned int x = 0;
				unsigned int y = 0;

				for (unsigned int i = 0; i < route.length(); i++)
				{
					c = route.at(i);
					direction = c-'0';
					x += dirX[direction];
					y += dirY[direction];

					if(lastDirection == direction)
					{
						counter ++;
					}
					else
					{
						arr[nNumOfWayPoints].Xpos = x;
						arr[nNumOfWayPoints].Ypos = y;
						x = 0;
						y = 0;
						lastDirection = direction;
						counter = 0;
						nNumOfWayPoints++;
					}
				}
				cout << "a";

			}
			else
			{
				cout << "No route found";
				cout << endl;
			}


}
