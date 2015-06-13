#include <string>
using namespace std;


struct StartLocationType {
		  int Xpos;
		  int Ypos;
		  int Yaw;;
		} ;
		struct GoalLocationType {
		  int Xpos;
		  int Ypos;
		} ;

const int BLANK = 255;
const int FULL = 0;
const int NEW_FULL = 1;

class Globals
{
	 static Globals *myGlobal;
	 Globals(){

	 }

public:
	static Globals* getInstance();
	StartLocationType StartLocation;
	GoalLocationType Goal;
	double MapResolutionCM, GridResolutionCM , RobotSize;
	size_t Pos;
	string  mapLocation;
};







