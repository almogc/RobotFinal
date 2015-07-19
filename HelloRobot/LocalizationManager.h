/*
 * LocalizationManager.h
 */

#include "Particle.h"
#include "Globals.h"

class LocalizationManager{
	static LocalizationManager *localObject;


public:
	Particle* arr_particles[PARTICLE_NUM];

	static LocalizationManager* getInstance();
	void initParticle(double dStartY, double dStartX, int** GridMap, int nGridWidth, int nGridHight);
	void UpdateBel(double DeltaX, double DeltaY, double Yaw, Robot* robot);
	Location GetHigeBel();
};
