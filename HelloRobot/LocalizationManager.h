/*
 * LocalizationManager.h
 */

#include "Particle.h"
#include "Globals.h"

class LocalizationManager{
private:
	Particle* arr_particles[PARTICLE_NUM];
public:
	void initParticle(double dStartY, double dStartX, int** GridMap, int nGridWidth, int nGridHight);
	void UpdateBel(double DeltaX, double DeltaY, double Yaw, Robot* robot);
	Location GetHigeBel();
};
