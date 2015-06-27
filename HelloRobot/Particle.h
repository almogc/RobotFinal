/*
 * Particle.h
 */

class Particle{

protected:
	double _locationX;
	double _locationY;
	double _yaw;
	double _belief;

public:
	Particle(double x, double y, double pYaw, double bel);
	virtual ~Particle();
	double getX() { return _locationX; }
	double getY() { return _locationY; }
	double getYaw() { return _yaw; }

};
