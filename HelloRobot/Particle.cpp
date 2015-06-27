/*
 * Particle.cpp
 */

#include "Particle.h"

Particle::Particle(double x, double y, double pYaw, double bel) : _locationX(x), _locationY(y), _yaw(pYaw), _belief(bel)
{
}

Particle::~Particle()
{
}
