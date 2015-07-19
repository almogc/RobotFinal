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
const int ANGLES_NUM = 667;
const int PARTICLE_NUM = 200;

#endif /* GLOBALS_H_ */
