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

Globals*  Globals::myGlobal=NULL;
Globals* Globals::getInstance()
{
	if(!myGlobal){

				myGlobal=new Globals();
			}
			return myGlobal;
}





