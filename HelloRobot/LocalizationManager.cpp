/*
 * LocalizationManager.cpp
 */

# include "LocalizationManager.h"
using namespace std;


void LocalizationManager::initParticle(double dStartY, double dStartX, int** GridMap, int nGridWidth, int nGridHight)
{
	for (int i = 0; i < PARTICLE_NUM; i++)
				{
					double x = (rand() % 10) - 5 + (dStartY);
					double y = (rand() % 10) - 5 +(dStartX);
					double yaw = rand() % (int)(ANGLES_NUM);
					if(GridMap[(int)x][(int)y]==0)
					{
						GridMap[(int)x][(int)y] = 5;

						Particle* p =new Particle(x, y,yaw,1,GridMap,nGridWidth,nGridHight);
						arr_particles[i] = p;
					}
					else
					{
						i--;
					}
				}
}


void LocalizationManager::UpdateBel(double DeltaX, double DeltaY, double Yaw, Robot* robot)
{
	for (int i = 0; i < PARTICLE_NUM; i++)
	{
		//cout << arr_particles[i]->getX() << " ---- " << arr_particles[i]->getY() << endl;
		arr_particles[i]->UpdateParticle(DeltaX,DeltaY,Yaw,robot);
		//cout << arr_particles[i]->getBelief() << endl;
	}
}

Location LocalizationManager::GetHigeBel()
{
	Location rLocation;
	int nMax=-999;
	for (int i = 0; i < PARTICLE_NUM; i++)
		{

			if(arr_particles[i]->getBelief() > nMax)
			{
				nMax = arr_particles[i]->getBelief();
				rLocation.Xpos = arr_particles[i]->getX();
				rLocation.Ypos = arr_particles[i]->getY();
				rLocation.Ypos = arr_particles[i]->getYaw();
			}


		}

		return (rLocation);
	}

