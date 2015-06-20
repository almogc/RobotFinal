/*
 * PathPlanner.h
 */

using namespace std;
#include<string>

class PathPlanner {
public:
	string AStarPathFind( const int & xStart, const int & yStart, const int & xFinish, const int & yFinish, int** GridMap, const int & Hight, const int & Width );

};
