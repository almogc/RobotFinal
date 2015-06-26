/*
 * PathPlanner.h
 */

#ifndef PATHPLANNER_H_
#define PATHPLANNER_H_

using namespace std;
#include<string>

class PathPlanner {
public:
	string AStarPathFind( const int nRowStart, const int nColStart, const int nRowFinish, const int nColFinish, int** GridMap, const int Hight, const int Width );
	void PrintPath(int** GridMap,const int nRowStart, const int nColStart, const int Hight, const int Width, string route);
};

#endif
