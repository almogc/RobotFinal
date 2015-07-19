#ifndef GLOBALS_H_
#define GLOBALS_H_

struct Location {
		  double Xpos;
		  double Ypos;
		  double Yaw;;
		} ;
struct StartLocationType {
		  double Xpos;
		  double Ypos;
		  double Yaw;;
		} ;
struct GoalLocationType {
		int Xpos;
		int Ypos;
} ;

const int BLANK = 255;
const int FULL = 0;
const int NEW_FULL = 1;
const double ANGLES_NUM = 6.28;
const int PARTICLE_NUM = 15;

#endif /* GLOBALS_H_ */
