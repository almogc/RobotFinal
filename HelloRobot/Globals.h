#ifndef GLOBALS_H_
#define GLOBALS_H_


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

#endif /* GLOBALS_H_ */
